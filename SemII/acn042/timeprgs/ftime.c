/*
  An example program that uses the ftime function and prints out the information returned. 
*/


#include <sys/timeb.h>
#include <stdio.h>
#include <sys/types.h>

void main ()
{
   struct timeb t1;

   int retval;

   retval = ftime (&t1);

   printf("Number of seconds: %d\n", t1.time);

    printf("Number of milliseconds: %d\n", t1.millitm);

    printf("Time zone: %d\n", t1.timezone);

     printf("Daylight savings time: %d\n", t1.dstflag);
}

