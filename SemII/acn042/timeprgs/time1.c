#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(void)
{
     struct tm *ptr;

      time_t lt;
 
      lt = time(NULL);

       ptr = localtime(&lt);

       printf(asctime(ptr));

        return(0);
}

