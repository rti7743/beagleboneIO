//
// contributed by: Dustin Mitchell <dmmitchel@gmail.com
// see: https://groups.google.com/forum/?fromgroups#!topic/beagleboard/alKf67dwMHI
// // modify by rti <super.rti@gmail.com>
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

#define CM_PER_REG_START 0x44e00000
#define CM_PER_REG_LENGTH 1024
#define CM_PER_EPWMSS0_CLKCTRL_OFFSET 0xd4
#define CM_PER_EPWMSS1_CLKCTRL_OFFSET 0xcc
#define CM_PER_EPWMSS2_CLKCTRL_OFFSET 0xd8

#define PWM_CLOCK_ENABLE 0x2
#define PWM_CLOCK_DISABLE 0x0

#define PWM_LIST_MAX 3

const int PWM_OFFSETS[PWM_LIST_MAX] = {
  CM_PER_EPWMSS0_CLKCTRL_OFFSET / sizeof (uint32_t),
  CM_PER_EPWMSS1_CLKCTRL_OFFSET / sizeof (uint32_t),
  CM_PER_EPWMSS2_CLKCTRL_OFFSET / sizeof (uint32_t)
};

const char* PWM_DEVICE_LIST[PWM_LIST_MAX] = {
	 "/sys/class/pwm/ehrpwm.1:1"
	,"/sys/class/pwm/ehrpwm.1:0"
	,"/sys/class/pwm/ehrpwm.0:0"
//	,"/sys/class/pwm/ehrpwm.0:1"
};


unsigned pwmNSOut(unsigned pin,unsigned period_ns,unsigned duty_ns) {

  int ret;
  char run_filename[256];
  char duty_ns_filename[256];
  char period_ns_filename[256];

  if (pin >= PWM_LIST_MAX) {
    return 0;
  }

  snprintf(period_ns_filename,256,"%s/period_ns",PWM_DEVICE_LIST[pin] );
  snprintf(duty_ns_filename,256,"%s/duty_ns",PWM_DEVICE_LIST[pin] );
  snprintf(run_filename,256,"%s/run",PWM_DEVICE_LIST[pin] );
	  
  ret = fileecho(run_filename,0);
  if (!ret) return 0;

  ret = fileecho(duty_ns_filename,0);
  if (!ret) return 0;

  ret = fileecho(period_ns_filename,period_ns);
  if (!ret) return 0;

  ret = fileecho(duty_ns_filename,duty_ns);
  if (!ret) return 0;

  ret =fileecho(run_filename,1);
  if (!ret) return 0;

  return 1;
}


unsigned pwmOut(unsigned pin,unsigned period_freq,unsigned duty_percent) {

  int ret;
  char run_filename[256];
  char duty_percent_filename[256];
  char period_freq_filename[256];

  if (pin >= PWM_LIST_MAX) {
    return 0;
  }

  snprintf(period_freq_filename,256,"%s/period_freq",PWM_DEVICE_LIST[pin] );
  snprintf(duty_percent_filename,256,"%s/duty_percent",PWM_DEVICE_LIST[pin] );
  snprintf(run_filename,256,"%s/run",PWM_DEVICE_LIST[pin] );
	  
  ret = fileecho(run_filename,0);
  if (!ret) return 0;

  ret = fileecho(duty_percent_filename,0);
  if (!ret) return 0;

  ret = fileecho(period_freq_filename,period_freq);
  if (!ret) return 0;

  ret = fileecho(duty_percent_filename,duty_percent);
  if (!ret) return 0;

  ret =fileecho(run_filename,1);
  if (!ret) return 0;

  return 1;
}

unsigned pwmRun(unsigned pin,int isrun) {

  int ret;
  char run_filename[256];

  if (pin >= PWM_LIST_MAX) {
    return 0;
  }

  snprintf(run_filename,256,"%s/run",PWM_DEVICE_LIST[pin] );
	  
  if (isrun) {
    ret = fileecho(run_filename,1);
  }
  else {
    ret = fileecho(run_filename,0);
  }
  if (!ret) return 0;

  return 1;
}
