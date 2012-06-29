#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/mman.h>

#include "beaglemem.h"
#include "beaglegpio.h"

#define MAX_PWM_PINS 3
const int PWM_OFFSETS[MAX_PWM_PINS] = {
  CM_PER_EPWMSS0_CLKCTRL_OFFSET / sizeof (uint32_t),
  CM_PER_EPWMSS1_CLKCTRL_OFFSET / sizeof (uint32_t),
  CM_PER_EPWMSS2_CLKCTRL_OFFSET / sizeof (uint32_t)
};

// I would like to use the memory instead of a file in fact. 
const char* PWM_DEVICE_LIST[PWM_LIST_MAX] = {
	 "/sys/class/pwm/ehrpwm.1:1"
	,"/sys/class/pwm/ehrpwm.1:0"
	,"/sys/class/pwm/ehrpwm.0:0"
//	,"/sys/class/pwm/ehrpwm.0:1"
};

int g_memory_fd = 0;
volatile unsigned long *g_memory = NULL;

unsigned long setBit(unsigned long reg, unsigned long mask) {
  return reg | mask;
} 

unsigned long clearBit(unsigned long reg, unsigned long mask) {
  return reg & (~mask);
} 

void setReg(unsigned long address, unsigned long reg) {
   g_memory[address/4] = reg;
   // if (DEBUG)  printf("Writting       %lx to %lx\n", address,reg);
}

unsigned long getReg(unsigned long address) {
  unsigned long result = 0;

  /*
  if (DEBUG) {
    printf("Reading Reg at %lx\n", address);
  }
  */
  result = g_memory[address/4];
  /*
  if (DEBUG) {
    printf("               %lx is %lx\n", address,result);
  }
  */
  return result;
}

// GIPIO MEM MAPPED IO VERSION
void digitalWriteFast(unsigned pin, unsigned int value) {
    assert(g_memory != MAP_FAILED);
    assert(pin < MAX_PINS);

    const unsigned long address = pins[pin].address + GPIO_DATAOUT;
    unsigned long reg = getReg(address);
    if (value)
      reg = setBit( reg, pins[pin].bitmask );
    else 
      reg = clearBit( reg, pins[pin].bitmask );
    setReg(address,reg);
}

// GIPIO MEM MAPPED IO VERSION
unsigned int digitalReadFast(unsigned pin) {
    assert(g_memory != MAP_FAILED);
    assert(pin < MAX_PINS);

    const unsigned long address = pins[pin].address + GPIO_DATAIN;
    unsigned long reg = getReg(address);
    return (reg & pins[pin].bitmask)  ? 0 : 1;
}


//PWM INIT
void pwm_ctor(int pwmNumber) {
    assert(g_memory != MAP_FAILED);
    assert(pwmNumber < MAX_PWM_PINS);

    setReg( PWM_OFFSETS[ pwmNumber - 1] ,  PWM_CLOCK_ENABLE);
}
void pwm_dtor(int pwmNumber) {
    assert(g_memory != MAP_FAILED);
    assert(pwmNumber < MAX_PWM_PINS);

    setReg( PWM_OFFSETS[ pwmNumber - 1] ,  PWM_CLOCK_DISABLE);
}



/*
void pwmEnable() {
//  unsigned long reg = getReg(CM_PER_EPWMSS1_CLKCTRL); 
  setReg(CM_PER_EPWMSS1_CLKCTRL,0x2); 
}
*/

void memmap_dtor() {
    if (g_memory) {
          close(g_memory_fd);
	  g_memory_fd = 0;
	  g_memory = NULL;
    }
}

int memmap_ctor() {
    assert(g_memory == NULL);
    // if (DEBUG) printf ("open file descriptor for GPIO\n");
    g_memory_fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (g_memory_fd < 0) {
      printf("Could not open GPIO memory fd\n");
      exit(0);
    }

    // GPIO configuration
    // if (DEBUG) printf ("Map GPIO\n");
    g_memory = (unsigned long*) mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE,
MAP_SHARED, g_memory_fd , MMAP_OFFSET);
    if (g_memory == MAP_FAILED) {
      printf ("GPIO Mapping failed\n");
      close(g_memory_fd );
      exit(0);
    }
    return 1;
}

