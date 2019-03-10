/* asctime example */

#include <stdio.h>
#include <time.h>

  main ()
 {
   time_t rawtime;

    struct tm * timeinfo;

     time ( &rawtime );

      timeinfo = localtime ( &rawtime );

      printf ( "The current date/time is: %s", asctime (timeinfo) );
  }

