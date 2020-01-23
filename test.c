#include <stdio.h>
#include <stdbool.h>
#include <arpa/inet.h>

int main(void) {
    //int k = htonl(0b01111111000000000000000000000001);
    int k = 0b01111111000000000000000000000001;
    int w = 2130706433;
    printf("%d\n%d\n", k, w);
    
    if(k == w)
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
/*
127 0 0 1
0111 1111   0000 0000   0000 0000   0000 0001
*/