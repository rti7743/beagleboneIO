#include "beaglebone.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void pinMode(const PIN pin, unsigned int value) {
  unsigned gpio;
  const Pair* pair;

  pair  = get_pair_with_key(pin.def, pin.no, "gpio");
  gpio = atoi(pair->value);

  if (value == INPUT) {
 //   // mux mode 0x27
 //   gpio_mux(&pin,  (_MUX_0 | _MUX_1 | _MUX_2 | _MUX_RECEIVER_ENABLE));
    gpio_mux(&pin,  0x37);
  }
  else {
    // mux mode 0x7
    gpio_mux(&pin, (_MUX_0 | _MUX_1 | _MUX_2));
  }

  gpio_export(gpio);
  gpio_set_direction(gpio, value);

}

void digitalWrite(const PIN pin, unsigned int value) {
  unsigned gpio;
  const Pair* pair;
  
  pair = get_pair_with_key(pin.def, pin.no, "gpio");
  gpio = atoi(pair->value);
  gpio_write_value(gpio, value);

} 

unsigned digitalRead(const PIN pin) {
  unsigned gpio;
  const Pair* pair;
  unsigned value;

  pair = get_pair_with_key(pin.def, pin.no, "gpio");
  gpio = atoi(pair->value);
  
  gpio_read_value(gpio, &value);

  return value ? 0 : 1;
}

unsigned analogRead(const unsigned pin) {
  FILE *f;
  char buf[128];
    unsigned value;
    snprintf(buf, sizeof(buf), "/sys/bus/platform/devices/tsc/ain%u", (pin + 1));
  if ((f = fopen(buf, "r")) != NULL) {
    fscanf(f, "%u", &value);
    fclose(f);
    return value;
  }
  perror("Cannot access analog pin");
  assert(0);
}

void shiftOut(const PIN dataPin, const PIN clockPin, unsigned bitOrder, unsigned value) {
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
