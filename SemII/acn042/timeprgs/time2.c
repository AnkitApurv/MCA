#include <time.h>
#include <stdio.h>


int main(void)
{
    printf("Elapsed time: %u secs.\n", clock()/CLOCKS_PER_SEC);
}

