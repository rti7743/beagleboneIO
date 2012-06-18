
#include "beagleutil.h"
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>



unsigned compute_pin_index(const char* pinStr) {
  unsigned x;
  unsigned y;

  if ((sscanf(pinStr, "P%u_%u", &x, &y)) == 2) {
    if ((x >= 8) && (x<=9) && (y >=1 && y<=46)) {
      return (x-8)*45 + y -1;
    }
  }
  // invalid conversion or invalid range
  return -1;
}

unsigned fileecho(const char * filename ,unsigned value) {
  int fd;
  char buffer[10];
  snprintf(buffer,sizeof(buffer),"%u",value);

  if ((fd = open(filename,O_WRONLY)) == -1) {
    return 0;
  }
  write(fd,buffer,strlen(buffer)+1 );
  close(fd);
  
  return 1;
}
unsigned fileechoX(const char * filename ,unsigned value) {
  int fd;
  char buffer[10];
  snprintf(buffer,sizeof(buffer),"%x",value);

  if ((fd = open(filename,O_WRONLY)) == -1) {
    return 0;
  }
  write(fd,buffer,strlen(buffer)+1 );
  close(fd);

  return 1;
}

unsigned fileecho_str(const char * filename , const char* str) {
  int fd;
  if ((fd = open(filename,O_WRONLY)) == -1) {
    return 0;
  }
  write(fd,str,strlen(str)+1 );
  close(fd);

  return 1;
}

unsigned fileoneline(const char * filename , unsigned * value) {
  int fd;
  int readlen;
  char buffer[128];
  if ((fd = open(filename,O_RDONLY)) == -1) {
    return 0;
  }
  readlen = read(fd,buffer,128 );
  close(fd);

  if (readlen < 0) {
    return 0;
  }
  *value = atoi(buffer);

  return 1;
} 

