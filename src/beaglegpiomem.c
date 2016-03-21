#ifdef FEATURE_GPIO_MEM


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/mman.h>

#include "beaglepair.h"
#include "beaglegpiomem.h"
#include "beaglebone.h"

unsigned long bankAddr[] = {
  GPIO0,
  GPIO1,
  GPIO2,
  GPIO3
};

volatile unsigned long *gpio;

inline unsigned long setBit(unsigned long reg, unsigned long mask) {
  return reg | mask;
} 

inline unsigned long clearBit(unsigned long reg, unsigned long mask) {
  return reg & (~mask);
} 

inline void setReg(unsigned long address, unsigned long reg) {
   gpio[address/4] = reg;
   // if (DEBUG)  printf("Writting       %lx to %lx\n", address,reg);
}

inline void latch(unsigned long address, unsigned long mask) {
  gpio[address/4] |= mask;
  gpio[address/4] &= ~mask;
}

inline unsigned long getReg(unsigned long address) {
  unsigned long result = 0;

  /*
  if (DEBUG) {
    printf("Reading Reg at %lx\n", address);
  }
  */
  result = gpio[address/4];
  /*
  if (DEBUG) {
    printf("               %lx is %lx\n", address,result);
  }
  */
  return result;
}

inline void gpioToMem(unsigned gpioNo, unsigned long *ret_addr, unsigned long *ret_bitMask) {
    assert(gpioNo != 0);

    unsigned bank = gpioNo / 32;
    unsigned bit = gpioNo % 32;
    assert(bank >= 0);
    /*
    printf("Selecting Pin '%s'\n in bank %d and bit %d aka pin #%d\n",
        pin.name,bank,bit,gpioNo);
    */
    //printf("GPIO%d_%d\n",bank,bit);
    assert(bank < 4);
    *ret_bitMask = 1 << bit;
    *ret_addr = bankAddr[bank];
    assert(*ret_bitMask);
    assert(*ret_addr);
}

inline void pinToMem(const PIN pin, unsigned long *ret_addr, unsigned long *ret_bitMask) {
    assert(gpio != MAP_FAILED);
    const Pair* pair = get_pair_with_key(pin.def, pin.no, "gpio");
    unsigned gpioNo = atoi(pair->value);
    gpioToMem(gpioNo, ret_addr, ret_bitMask);
}

inline void digitalWrite_addr(  unsigned long addr,
                                unsigned long bitMask,
                                unsigned value) {
    if (value) {
      gpio[(addr + GPIO_DATAOUT) / 4 ] |= bitMask;
    } else  {
      gpio[(addr + GPIO_DATAOUT) / 4] &= ~bitMask;
    }
}

inline void digitalWrite(const PIN pin, unsigned int value) {
  unsigned long addr;
  unsigned long bitMask;
  pinToMem(pin, &addr, &bitMask);    
  digitalWrite_addr(addr,bitMask,value);
}

void pinMode_raw(const PIN pin, unsigned mode, GPIO* out_gpio) {
  pinMode(pin,mode);

  assert(out_gpio);
  unsigned long addr;
  unsigned long bitMask;

  pinToMem(pin, &addr, &bitMask);
  assert(gpio != MAP_FAILED);
  out_gpio->rawAddr = &(gpio[(addr + ((mode == OUTPUT) ? GPIO_DATAOUT : GPIO_DATAIN)) / 4]);
  out_gpio->bitMask = bitMask;
  assert(out_gpio->rawAddr);
  assert(out_gpio->bitMask);
}

void digitalWrite_raw(GPIO* g, unsigned int value) {
    if (value) {
      *(g->rawAddr) |= g->bitMask;
    } else  {
      *(g->rawAddr) &= ~g->bitMask;
    }
}

unsigned digitalRead_raw(GPIO* g) {
  return (*(g->rawAddr) & g->bitMask) ? 1 : 0;
}

inline void digitalLatch_raw(GPIO* g) {
  volatile unsigned long* word_ptr = g->rawAddr;
  (*word_ptr) |= g->bitMask;
  (*word_ptr) &= ~g->bitMask;
}

inline unsigned digitalRead(const PIN pin) {
    unsigned long addr;
    unsigned long bitMask;

    pinToMem(pin, &addr, &bitMask);
    unsigned long reg = getReg(addr + GPIO_DATAIN);
    return (reg & bitMask) ? 1 : 0;
}

int setup_gpio_mem_map() {
    // if (DEBUG) printf ("open file descriptor for GPIO\n");
    int gpio_fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (gpio_fd < 0) {
      printf("Could not open GPIO memory fd\n");
      exit(0);
    }

    // GPIO configuration
    // if (DEBUG) printf ("Map GPIO\n");
    gpio = (unsigned long*) mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE,
MAP_SHARED, gpio_fd, MMAP_OFFSET);
    if (gpio == MAP_FAILED) {
      printf ("GPIO Mapping failed\n");
      close(gpio_fd);
      exit(0);
    }
    printf("Using Memory Mapped IO for digital Reads and Writes\n");
    return 1;
}

#endif
