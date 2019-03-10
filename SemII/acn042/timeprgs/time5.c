#include <stdio.h>
#include <sys/time.h>


int main ()
{
   struct timeval the_time;

   struct timezone the_zone;

    gettimeofday (&the_time, &the_zone);

    printf ("Number of seconds: %d\n", the_time.tv_sec);

    printf ("Number of microseconds: %d\n", the_time.tv_usec);

    printf ("Time zone: %d\n", the_zone.tz_minuteswest);

    printf ("Daylight savings time: %d\n", the_zone.tz_dsttime);
}

