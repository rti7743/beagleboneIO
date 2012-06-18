/** @file beagleutil.h
 * Utility functions.
 *
 */

#ifndef _UTIL_H
#define _UTIL_H

/** compute the index of a given pin in the pin structure.
 * @param pinStr a string, such as "P8_35"
 * @return the index inside the pin structure for this input
 */
extern unsigned compute_pin_index(const char* pinStr);

extern unsigned fileecho(const char * filename ,unsigned value) ;
extern unsigned fileechoX(const char * filename ,unsigned value) ;
extern unsigned fileecho_str(const char * filename , const char* str) ;
extern unsigned fileoneline(const char * filename , unsigned * value) ;

#endif /* _UTIL_H */
