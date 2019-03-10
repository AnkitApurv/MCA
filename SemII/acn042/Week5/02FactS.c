/* @desc  The client stores an array of integers in a shared memory. 
The server finds the factorial of these integers and returns the results to the client machine. 
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

int findFactorial(int k) {
	if(k > 1)
		return k * findFactorial(k-1);
	else if(k == 1)
		return 1;
	else //k <= 0
		return 0;
}

int main(void) {

	const int memoryFlag = 0;
	const int arraySize = 5;
	const int memorySize = sizeof(int) * arraySize;
	key_t key = ftok(".", 42);
	const char begin = '#';
	const char done = '@';

	printf("02 Factorial Server\n");

	int sharedMemoryID = shmget(key, memorySize, IPC_CREAT | 0666);
	if(sharedMemoryID == -1) return -1;
	char *memoryBlock = shmat(sharedMemoryID, NULL, memoryFlag);
	if(memoryBlock == (char*)-1) return -1;

	int numbers[5], factorial[5], i;

	//recieving data
	printf("recieving data\n");
	printf("waiting for signal\t");
	while(*memoryBlock != begin) { } //waiting for signal
	printf("copy data from shared memory\t");
	memcpy(numbers, memoryBlock, sizeof(int) * arraySize); //copy data from shared memory
	printf("done\n");
	memcpy(memoryBlock, &done, sizeof(char));	//done

	printf("Recieved array of integers\n");
	for(i=0; i<arraySize; i++)
		printf("%d\t", numbers[i]);
	printf("\n");

	//processing
	for(i=0; i<arraySize; i++)
		factorial[i] = findFactorial(numbers[i]);

	printf("Factorial(int)\n");
	for(i=0; i<arraySize; i++)
		printf("%d\t", factorial[i]);
	printf("\n");

	//sending data
	printf("sending data\n");
	//printf("signal begin\t");
	//memcpy(memoryBlock, &begin, sizeof(char));	//signal begin
	printf("copy result to shared memory\n");
	memcpy(memoryBlock, factorial, sizeof(int) * arraySize); //copy result to shared memory
	shmdt(memoryBlock);	//job done

	return 0;
}