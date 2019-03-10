/*
    You may pass a pointer to a time_t, and the time will not only be returned from the function, but it is also placed 
    at that address.
*/
#include <stdio.h>
#include <time.h>

void main()
{
    time_t the_time;

    time (&the_time);

     printf ("%d\n", the_time);
}



