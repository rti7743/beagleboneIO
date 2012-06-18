#include "beaglegpio.h"

#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <beagleutil.h>

static const char *gpioPath[] = {       // index
  "/sys/class/gpio/export",             // 0
  "/sys/class/gpio/unexport",           // 1
  "/sys/class/gpio/gpio%u/direction",   // 2
  "/sys/class/gpio/gpio%u/value",       // 3
  "/sys/class/gpio/gpio%u/edge",        // 4
  "/sys/class/gpio/gpio%u/active_low",  // 5
};

void gpio_inspect(unsigned pin) {
  assert(pin < MAX_PINS);

  printf("Name: %s\n", pins[pin].name);
  printf("\tgpio:  %d\n", pins[pin].gpio);
  printf("\tmux:   %s\n", pins[pin].mux);
  printf("\eeprom: %d\n", pins[pin].eeprom);
}

void gpio_mux(unsigned pin, unsigned value) {
  char filename[128];

  assert(pin < MAX_PINS);
  assert(pins[pin].mux[0] != '\0');
  sprintf(filename, "/sys/kernel/debug/omap_mux/%s", pins[pin].mux);
  if (! fileechoX(filename,value) ) {
    perror("can't open pin for muxing");
    assert(0);
  }
}

void gpio_export(unsigned pin) {
  assert(pin < MAX_PINS);

  if (! fileecho(gpioPath[0],pins[pin].gpio) ) {
    perror("failed to export pin");
    assert(0);
  }
}

void gpio_unexport(unsigned pin) {
  assert(pin < MAX_PINS);

  if (! fileecho(gpioPath[1],pins[pin].gpio) ) {
    perror("failed to unexport pin");
    assert(0);
  }
}

void gpio_set_direction(unsigned pin, unsigned direction) {
  char filename[128];
  const char * writeString;

  assert(pin < MAX_PINS);
  snprintf(filename, sizeof(filename), gpioPath[2], pins[pin].gpio);
  switch (direction) {
    case INPUT: writeString = "in";
      break;
    case OUTPUT: writeString = "out";
      break;
    default:
      assert(0);
  }
  if ( ! fileecho_str(filename, writeString) ) {
    perror("Failed to set direction for pin");
    assert(0);
  }
  return;
}

void gpio_write_value(unsigned pin, unsigned value) {
  int fd;

  assert(pin < MAX_PINS);
  if ((fd = gpio_get_fd(pin,O_WRONLY)) != -1) {
    if (value) {
      write(fd, "1", 2);
    }
    else {
      write(fd, "0", 2);
    }
    gpio_close_fd(fd);
    return;
  }
  perror("failed to set value for pin");
  assert(0);
}

unsigned gpio_read_value(unsigned pin) {
  int fd;
  int readSize;
  char buf[128];

  assert(pin < MAX_PINS);
  if ((fd = gpio_get_fd(pin,O_RDONLY)) != -1) {
    readSize = read(fd,buf,128);
    if (readSize < 0) {
      gpio_close_fd(fd);
      perror("Failed to get zero length");
      assert(0);
      return 0;
    }
    buf[readSize] = '\0';
    gpio_close_fd(fd);
    return atoi(buf);
  }

  perror("Failed to get value for pin");
  assert(0);
  return 0;
}

void gpio_set_edge(unsigned pin, const char* edge) {
  char filename[128];

  assert(pin < MAX_PINS);
  snprintf(filename, sizeof(filename), gpioPath[4], pins[pin].gpio);
  if ( ! fileecho_str(filename,edge) )
  {
    perror("failed to set edge");
    assert(0);
  }
}

void gpio_set_active_low(unsigned pin, unsigned value) {
  char filename[128];

  assert(pin < MAX_PINS);
  assert(value == HIGH || value == LOW);
  snprintf(filename ,sizeof(filename), gpioPath[5], pins[pin].gpio);
  if ( ! fileecho(filename,value) )
  {
    perror("failed to set active low for pin");
    assert(0);
  }
}


int gpio_get_fd(unsigned pin, int flag) {
  int fd;
  char filename[128];

  assert(pin < MAX_PINS);
  // gpioPath[3] = "/sys/class/gpio/gpio%u/value"
  snprintf(filename, sizeof(filename),gpioPath[3], pins[pin].gpio);
  fd = open(filename, flag );
  assert(fd != -1);
  return fd;
}

void gpio_close_fd(int fd) {
  close(fd);
}


