

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "beagleutil.h"
#include "beaglebone.h"

static const struct option longOpts[] = {
  { "pin", required_argument, NULL, 'p' },
  { "help", no_argument, NULL, 'h'},
  { NULL, no_argument, NULL, 0}
};

static const char *optString = "p:v:h";

static char* pinStr;

static int pinIndex = -1;
static int helpDisplayed = 0;

void display_usage() {
  printf("digitalRead --pin <pin>\n");
  printf("\t<pin>\te.g. P8_45\n");
  printf("\n");
}


void doDigitalRead(unsigned pinIndex) {
  unsigned value;

  memmap_ctor();
  pinMode(pinIndex, INPUT);
  value = digitalRead(pinIndex);

  printf("%u\n",value);
}


int main(int argc, char **argv) {
  int opt;
  while ((opt = getopt_long(argc, argv, optString, longOpts, NULL)) != -1) {
    switch(opt) {
    case 'p':
      pinStr = optarg;
      pinIndex = compute_pin_index(pinStr);
      break;
    case 'h':
    case '?':
	display_usage();
        helpDisplayed = 1;
	return EXIT_SUCCESS;
      break;
    default:
      break;
    }
  }
  if (pinIndex != -1) {
    doDigitalRead(pinIndex);
  }
  else {
    display_usage();
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

