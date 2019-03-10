//Number of Seconds Since January 1, 1970


#include <time.h>
#include <stdio.h>

main()
{
  time_t t1;

  time (&t1);


  printf("%d\n", t1);
}
