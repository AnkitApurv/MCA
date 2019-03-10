/* @desc  The client stores an operator and corresponding operands in a shared memory. 
These contents are read by the server and the result is processed and returned back to the client accordingly. 15
@name Ankit Apurv 180970042
@date 10/02/2019
@desc client
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

struct ops {
	int op1, op2, operator, result;
};

int main(void)
{
	const int memoryFlag = 0;
	const int memorySize = 100;
	key_t key = ftok(".", 37);
	const char begin = '#';
	const char done = '@';
	
	printf("03 Calculator Client\n");

	struct ops work;
	printf("a : ");
	scanf("%d", &work.op1);
	printf("b : ");
	scanf("%d", &work.op2);
	printf("\nOperations \n 1.Division \n 2.Multiplication \n 3.Addition \n 4.Substraction \n Choice(int) : ");
	scanf("%d", &work.operator);
	
	work.result = 0;
	
	int sharedMemoryID = shmget(key, memorySize, 0666);
	if(sharedMemoryID == -1) return -1;
	char *memoryBlock = shmat(sharedMemoryID, NULL, memoryFlag);
	if(memoryBlock == (void*)-1) return -1;

	//memcpy(void *dest, const void *src, size_t n);
	printf("writing begin\n");
	memcpy(memoryBlock, &begin, sizeof(char));	//signal begin
	printf("writing struct\n");
	memcpy(memoryBlock, &work, sizeof(struct ops));
	printf("struct written, waiting for done signal\n");
	while(*memoryBlock != done) {}	//is done?
	printf("recieved done signal\n");

	printf("waiting for begin signal\n");
	while(*memoryBlock != begin) {} //waiting for begin signal
	printf("recieved begin, reading result\n");
	memcpy(&work, memoryBlock, sizeof(struct ops));
	shmdt(memoryBlock);	//job done
	
	shmctl(sharedMemoryID, IPC_RMID, NULL);

	printf("Result = %d\n", work.result);
	return 0;
}
