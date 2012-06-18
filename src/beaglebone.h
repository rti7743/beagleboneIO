/** @file beaglebone
 *  @brief basic procedures the beaglebone/io library
 */
#ifndef _BEAGLEBONE_H
#define _BEAGLEBONE_H

#include "beaglegpio.h"
#include "beagledelay.h"
#include "beagleutil.h"

/** Least significant byte first
 *
 */
#define LSBFIRST 1

/** Most significant byte first
 *
 */
#define MSBFIRST 0

/** set a GPIO pin mode.
 *
 * set a GPIO pin into a particular mode.
 * @param pin the desired PIN
 * @param mode INPUT or OUTPUT
 *
 */
extern void pinMode(unsigned pin, unsigned mode);

/** write to a pin.
 *
 * write the value to the specified pin
 * @param pin the desired pin
 * @param value either HIGH or LOW
 */
extern void digitalWrite(unsigned pin, unsigned value);

extern unsigned pwmEnable(unsigned pin,unsigned isenable);
extern unsigned pwmOut(unsigned pin,unsigned preiod_freq,unsigned duty_percent);
extern unsigned pwmNSOut(unsigned pin,unsigned period_ns,unsigned duty_ns) ;
extern unsigned pwmRun(unsigned pin,unsigned isrun);
extern unsigned analogWrite(unsigned pin,unsigned value);


/** read from a pin.
 * 
 * read a value from the specific pin
 * @param pin the desired pin
 * @return the value 
 */
extern unsigned digitalRead(unsigned PIN);

/** read from an analog pin.
 *
 * @param pin the number of the analog pin specified a 0..6
 * @return the read value
 */
extern unsigned analogRead(unsigned pin);

/** push the value serially to the dataPin.
 * Writes the designated byte in value bitwise to the dataPin, using clockPin 
 * as clock.
 * The implementation is an exact copy of the algorithm found in bonescript.
 * @param dataPin the datapin
 * @param clockPin the clockpin
 * @param bitOrder one of LSBFIRST or MSBFIRST
 * @param value the value to write
 */
extern void shiftOut(unsigned dataPin,unsigned clockPin,unsigned bitOrder,unsigned value);

/**
 * Run a programm.
 * Executes the setup function once and loops over the loop function. The loop
 * will be executed as long as the function loop returns a non 0 value.
 * @param setup a pointer to a function returning void with no parameters
 * @param loop a pointer to a function returning an int. 
 */
extern void run(void (*setup)(void), int (*loop)(void));
#endif
