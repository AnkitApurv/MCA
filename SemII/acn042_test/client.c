/*client*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>	//memcpy()

int main(void) {

	char s[100];
	FILE *f1 = fopen("f1.txt", "a+");
	gets(s);
	fputs(s, f1);
	fclose(f1);
	
	key_t k = ftok(".", 68);
	
	int shmID = shmget(k, sizeof(char)*150, 0666);
	if(shmID < 0) return -1;
	char* shmBlk = shmat(shmID, NULL, 0);
	const char begin = '$';
	
	printf("sending initial\n");
	memcpy(shmBlk, &begin, sizeof(char));
	wait(0);
	memcpy(shmBlk, s, sizeof(s));
	printf("sent initial\n\n");
	
	FILE* f2 = fopen("f2.txt", "a+");
	printf("recieving sorted\n");
	while(*shmBlk != begin) { }
	printf("sorted begin\n");
	memcpy(s, shmBlk, sizeof(s));
	printf("sorted recieved\n\n");
	fputs(s, f2);
	puts(s);
	fclose(f2);
	
	
	FILE* f3 = fopen("f3.txt", "a+");
	printf("recieving reversed sorted\n");
	while(*shmBlk != begin) { }
	printf("reversed sorted begin\n");
	memcpy(s, shmBlk, sizeof(s));
	printf("reversed sorted recieved\n\n");
	fputs(s, f3);
	puts(s);
	fclose(f3);
	
	shmdt(shmBlk);
	shmctl(shmID, IPC_RMID, 0);
	
	return 0;	
}
