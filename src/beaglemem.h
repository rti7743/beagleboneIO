#ifndef _GPIO_MEM_H

#define MMAP_OFFSET 0x44c00000
#define MMAP_SIZE   (0x48ffffff - MMAP_OFFSET)


/* for GPIO */
#define GPIO0_MEM   (0x44e07000 - MMAP_OFFSET)
#define GPIO1_MEM   (0x4804c000 - MMAP_OFFSET)
#define GPIO2_MEM   (0x481ac000 - MMAP_OFFSET)
#define GPIO3_MEM   (0x481ae000 - MMAP_OFFSET)

#define GPIO_OE           0x134
#define GPIO_DATAIN       0x138
#define GPIO_DATAOUT      0x13c
#define GPIO_CLEARDATAOUT 0x190
#define GPIO_SETDATAOUT   0x194

/* for PWM */
#define CM_PER_BASE (0x44e00000 - MMAP_OFFSET)
#define CM_PER_EPWMSS1_CLKCTRL (CM_PER_BASE + 0xcc)
#define CM_PER_EPWMSS0_CLKCTRL (CM_PER_BASE + 0xd4)
#define CM_PER_EPWMSS2_CLKCTRL (CM_PER_BASE + 0xd8)
#define PWM_CLOCK_ENABLE  0x02
#define PWM_CLOCK_DISABLE 0x00

extern int  memmap_ctor(); 
extern void memmap_dtor(); 
extern void digitalWriteFast(unsigned pin,unsigned int value);
extern unsigned int digitalReadFast(unsigned pin);
//extern void pwmEnable();
//


#define GPIO_MEMORY_TO(gpioNo) (( (gpioNo) / 32) == 0 ? GPIO0_MEM : (( (gpioNo) / 32) == 1 ? GPIO1_MEM : (( (gpioNo) / 32) == 2 ? GPIO2_MEM : GPIO3_MEM )  ) )
#define GPIO_BIT_TO(gpioNo) (1 << (gpioNo)%32)

#endif
