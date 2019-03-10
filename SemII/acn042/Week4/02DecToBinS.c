/* @desc Write a client server program to convert an array of decimal numbers to their binary equivalent forms. 
@name Ankit Apurv 180970042
@date 10/02/2019
@desc server
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>

struct message {
	long type;
	char content[100];
};

//left to right - lsb to msb
void decToBin(int k, short bin[32])
{
	int i = 0;
	while(k > 0 && i < 32)
	{
		bin[i] = k % 2;
		printf("%d", bin[i++]);
		k /= 2;
	}
	printf("\n");
	return;
}

int main(void)
{
	printf("02 Binary to Decimal Server\n");
	const int arraySize = 2;
	int i, j, iA[arraySize];

	short bA[arraySize][32];
	for(i=0; i<arraySize; i++)
		for(j=0; j<32; j++)
			bA[i][j] = 0;


	const int messageFlag = 0;
	const int clientToServer = 1;
	const int serverToClient = 2;


	int messageID = msgget((key_t)40, 0666 | IPC_CREAT);
	struct message intsMsg;
	for(i=0; i<arraySize; i++)
	{
		msgrcv(messageID, &intsMsg, sizeof(intsMsg), clientToServer, messageFlag);
		memcpy(&iA[i], intsMsg.content, sizeof(int));
		printf("%d\n", iA[i]);
	}
	msgctl(messageID, IPC_RMID, NULL);

	for(i=0; i<arraySize; i++)
		decToBin(iA[i], &bA[i][0]);

	messageID = msgget((key_t)45, 0666 | IPC_CREAT);
	struct message binsMsg;
	binsMsg.type = serverToClient;
	for(i=0; i<arraySize; i++)
	{
		for(j=31; j>=0; j--)
			printf("%d", bA[i][j]);
		printf("\n");
		memcpy(binsMsg.content, bA[i], sizeof(bA[i]));
		msgsnd(messageID, &binsMsg, sizeof(binsMsg), messageFlag);
	}
	return 0;
}