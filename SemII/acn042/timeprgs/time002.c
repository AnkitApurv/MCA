/*
    char *ctime(const time_t *time);

    returns a time in string, whose form is: day month year hours:minutes:seconds year\n\0
*/

#include <time.h>
#include <stdio.h>

 void main()
  {
   time_t lt;

    lt = time(NULL);

    printf(ctime(&lt));

    return 0;
  }

