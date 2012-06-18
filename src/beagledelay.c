
#include "beagledelay.h"
#include <sys/time.h>

int delayMicro(useconds_t useconds) {
  return usleep(useconds);
}

unsigned long micros() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (tv.tv_sec %1000*1000000) + tv.tv_usec; /* it slow.... */
}
