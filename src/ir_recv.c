#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <math.h>

#include "beagleutil.h"
#include "beaglebone.h"


unsigned long micros()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
//  printf("\n%u %u %u %u ",tv.tv_sec,tv.tv_usec,(tv.tv_sec%1000*1000000),(tv.tv_sec %1000*1000000) + tv.tv_usec);

//  return (tv.tv_sec << 20) + tv.tv_usec;
  return (tv.tv_sec %1000*1000000) + tv.tv_usec;
}

void delayMicroseconds(unsigned int microsecond)
{
  usleep(microsecond);
}

int ir_receive(unsigned ir_in,unsigned long* outData,int len,int* outLen)
{
  unsigned int val = 0;
  unsigned int before_val = 1;
  unsigned timeoutTimer = 0;  //micro second tanni nano de besy loop de.
  const unsigned FIRST_TIMEOUT = 10000000;
  const unsigned END_TIMEOUT   = 1000000;
  struct timeval* tv = (struct timeval*)malloc(sizeof(struct timeval) * (len+1));
  struct timeval* tvNow = &tv[0];
  struct timeval* tvEnd = &tv[len+1];
  int cnt;
  puts("----- IR RECEIVE MODE -----");

  //first
  timeoutTimer = 0;
  while( ! digitalRead(ir_in) )
  {
     if (++timeoutTimer >= FIRST_TIMEOUT)
     {
         puts("time out!");
	 free(tv);
         return 0;
     }
  }

  timeoutTimer = 0;
  gettimeofday(tvNow++, NULL);
  while(1)
  {
     while( (val = digitalRead(ir_in)  ) ==  before_val )
     {
        if (++timeoutTimer >= END_TIMEOUT)
        {
           break;
        }
     }
     gettimeofday(tvNow, NULL);

     if (timeoutTimer >= END_TIMEOUT) break;
     if (tvNow == tvEnd) break;

     tvNow ++;
     before_val = val;
     timeoutTimer = 0;
  }


  cnt = 0;
  tvEnd = tvNow;
  for (tvNow = &tv[1] ; tvNow != tvEnd ; ++tvNow)
  {
     outData[cnt] = ((tvNow->tv_sec %1000*1000000) + tvNow->tv_usec) 
	        - (( (tvNow-1)->tv_sec %1000*1000000) + (tvNow-1)->tv_usec);

     printf("%lu,",outData[cnt]);
     cnt ++;
  }
  *outLen = cnt;
  free(tv);

  puts("");
  puts("----- RECEIVE DONE -----");
  return 1;
}

int ir_send(unsigned ir_out,unsigned long* data,int len)
{
  register int cnt = 0;

  puts("----- IR SEDN MODE -----");

  for (cnt = 0; cnt < len; cnt++) 
  {
    printf("%lu,",data[cnt]);
  }
  digitalWrite(ir_out,0);
  puts("start.");
  pwmNSOut(1,26300,8800);

  for (cnt = 0; cnt < len; cnt++) 
  {
    digitalWrite(ir_out,1-(cnt&1));
    usleep(data[cnt] );
/*
      if (cnt & 0x1) {
         digitalWrite(ir_out,0);
         usleep(data[cnt]);
      } else {
         unsigned long loopCount  = (data[cnt] / (9+17)) + 1;
	 for( ; loopCount ; loopCount -- ) {
            digitalWrite(ir_out,1);
            usleep(9);
            digitalWrite(ir_out,0);
            usleep(17);
	 }
      }
*/
  }
  digitalWrite(ir_out,0);
  pwmRun(1,0);

  puts("ok");
  puts("----- SEND DONE ------");
  
  return 1;
}

int ir_save(const char * filename , unsigned long* data,int len)
{
  FILE * fp = fopen(filename,"wb");
  if (!fp)
  {
    return 0;
  }
  fwrite(data,sizeof(unsigned long),len,fp);
  fclose(fp);

  return 1;
}

int ir_load(const char * filename , unsigned long* data,int len,int* outLen)
{
  struct stat statbuf;
  stat(filename, &statbuf);

  FILE * fp = fopen(filename,"rb");
  if (!fp)
  {
    return 0;
  }
  *outLen = fread(data,sizeof(unsigned long),(statbuf.st_size > len ? statbuf.st_size : len),fp);
  fclose(fp);

  return 1;
}


int main(int argc, char **argv)
{
	unsigned long data[1024];

	int datalen = 0;
	int ret = 0;

	memmap_ctor();

	printf("argc :%d %c\n",argc,argv[1][0]);
	if (argc >= 2 && argv[1][0] == 'l')
	{
		pinMode(P8_3, INPUT);
		ret = ir_receive(P8_3,data,1024,&datalen);
		if (!ret)
		{
			puts("ERROR!!");
			return -1;
		}
		ir_save("ir1.dat",data,datalen);
		return 0;
	}
	if (argc >= 2 && argv[1][0] == 's')
	{
		pinMode(P8_4, OUTPUT);
		ret = ir_load("ir1.dat",data,1024,&datalen);
		if (!ret)
		{
			puts("ERROR!!");
			return -1;
		}
		printf("load %d byte\n",datalen);
	
		ret = ir_send(P8_4,data,datalen);
		if (!ret)
		{
			puts("ERROR!!");
			return -1;
		}
		return 0;
	}
	memmap_dtor();

	return 0;
}
