#include "beaglebone.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void pinMode(unsigned pin, unsigned int value) {

  if (value == INPUT) {
 //   // mux mode 0x27
 //   gpio_mux(&pin,  (_MUX_0 | _MUX_1 | _MUX_2 | _MUX_RECEIVER_ENABLE));
    gpio_mux(pin,  0x37);
  }
  else {
    // mux mode 0x7
    gpio_mux(pin, (_MUX_0 | _MUX_1 | _MUX_2));
  }

  gpio_export(pin);
  gpio_set_direction(pin, value);

}

void digitalWrite(unsigned pin, unsigned int value) {
//  gpio_write_value(pin, value);
  digitalWriteFast(pin,value);
} 

unsigned digitalRead(unsigned pin) {
//  return gpio_read_value(pin) ? 0 : 1;
  return digitalReadFast(pin);
}

unsigned analogRead(unsigned pin) {
  char filename[128];
  unsigned value;

  snprintf(filename, sizeof(filename), "/sys/bus/platform/devices/tsc/ain%u", (pin + 1));
  if ( ! fileoneline(filename,&value) ) {
    perror("Cannot access analog pin");
    assert(0);
    return 0;
  }

  return value;
}

unsigned analogWrite(unsigned pin,unsigned value) {
  if (value == 0) {
    return pwmRun(pin,0);
  }
  if (value > 255) value = 255;
  return pwmOut(pin,490,value*100/255);
}


void shiftOut(unsigned dataPin, unsigned clockPin, unsigned bitOrder, unsigned value) {
  unsigned i;
  unsigned bit;

  for (i = 0; i < 8 ; i++) {
    if (bitOrder == LSBFIRST) {
      bit = value & (1 << i);
    }
    else {
      bit = value & (1 << (7-i));
    }
    digitalWrite(dataPin, bit);
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW); 
  }
}

void run(void (*setup)(void), int  (*loop)(void)) {
  (*setup)();
  while (((*loop)()) != 0) {}
}
