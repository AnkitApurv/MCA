/* @desc  The client stores an array of integers in a shared memory. 
The server finds the factorial of these integers and returns the results to the client machine. 
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

int main(void) {

	const int memoryFlag = 0;
	const int arraySize = 5;
	const int memorySize = sizeof(int) * arraySize;
	key_t key = ftok(".", 42);
	const char begin = '#';
	const char done = '@';
	
	printf("02 Factorial Client\n");

	int sharedMemoryID = shmget(key, memorySize, 0666);
	if(sharedMemoryID == -1) return -1;
	char *memoryBlock = shmat(sharedMemoryID, NULL, memoryFlag);
	if(memoryBlock == (char*)-1) return -1;

	int numbers[5], factorial[5], i;

	printf("Input %d integers\n", arraySize);
	for(i=0; i<arraySize; i++)
		scanf("%d", &numbers[i]);
	printf("Recieved array of integers\n");

	//sending data
	printf("sending data\n");
	printf("signal begin\t");
	memcpy(memoryBlock, &begin, sizeof(char));	//signal begin
	printf("copy data to shared memory\t");
	memcpy(memoryBlock, numbers, sizeof(int)*arraySize); //copy data to shared memory
	printf("is done?\n");
	while(*memoryBlock != done) { }	//is done?

	sleep(1);

	//recieveing data
	printf("recieveing data\n");
	//printf("waiting for begin signal\t");
	//while(*memoryBlock != begin) { } //waiting for begin signal
	printf("copy result from shared memory\n");
	memcpy(factorial, memoryBlock, sizeof(int)*arraySize); //copy result from shared memory
	shmdt(memoryBlock);	//job done
	
	//remove shared memory segment
	shmctl(sharedMemoryID, IPC_RMID, NULL);

	printf("Factorial(int)\n");
	for(i=0; i<arraySize; i++)
		printf("%d\t", factorial[i]);
	printf("\n");

	return 0;
}