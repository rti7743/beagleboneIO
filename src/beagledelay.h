/**
 * @file beagledelay
 * @brief Utilities to delay program execution
 */
#ifndef _BEAGLEDELAY_H
#define _BEAGLEDELAY_H

#include <unistd.h>

/**
 * delay in microsencods.
 */
extern int delayMicro(useconds_t useconds);

/**
 * get microsencods.
 */
extern unsigned long micros();


#endif /* _BEAGLEDELAY_H */
