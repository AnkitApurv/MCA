/* @desc  The client stores an operator and corresponding operands in a shared memory. 
These contents are read by the server and the result is processed and returned back to the client accordingly. 15
@name Ankit Apurv 180970042
@date 10/02/2019
@desc server
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

	printf("03 Calculator Server\n");
	
	int sharedMemoryID = shmget(key, memorySize, 0666 | IPC_CREAT);
	if(sharedMemoryID == -1) return -1;
	char *memoryBlock = shmat(sharedMemoryID, NULL, memoryFlag);
	if(memoryBlock == (void*)-1) return -1;

	struct ops work;

	//memcpy(void *dest, const void *src, size_t n);
	printf("waiting for begin signal\n");
	while(*memoryBlock != begin) {} //waiting for signal
	printf("recieved begin signal, getting struct\n");
	memcpy(&work, memoryBlock, sizeof(struct ops));
	printf("struct recieved\n");
	memcpy(memoryBlock, &done, sizeof(char));	//done
	printf("sending done signal\n");
	
	
	switch(work.operator)
	{
		case 1:
			work.result = work.op1/work.op2;
			break;
		case 2:
			work.result = work.op1*work.op2;
			break;
		case 3:
			work.result = work.op1+work.op2;
			break;
		case 4:
			work.result = work.op1-work.op2;
			break;
		default:
			work.result=0;
	}
	//client must sleep after sending choice so server can prepare result before client attempts to read it
	printf("sending begin signal\n");
	memcpy(memoryBlock, &begin, sizeof(char));	//signal begin
	printf("sending result struct\n");
	memcpy(memoryBlock, &work, sizeof(struct ops));
	shmdt(memoryBlock);	//job done
	//shmctl(sharedMemoryID, IPC_RMID, NULL); client should destroy after reading

	printf("Result = %d\n", work.result);
	return 0;
}
