/* @desc Write a client server program to convert an array of decimal numbers to their binary equivalent forms. 
@name Ankit Apurv 180970042
@date 10/02/2019
@desc client
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

int main(void)
{
	printf("02 Binary to Decimal Client\n");
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
	intsMsg.type = clientToServer;
	for(i=0; i<arraySize; i++)
	{
		scanf("%d", &iA[i]);
		memcpy(intsMsg.content, &iA[i], sizeof(int));
		msgsnd(messageID, &intsMsg, sizeof(intsMsg), messageFlag);
	}

	messageID = msgget((key_t)45, 0666 | IPC_CREAT);
	struct message binsMsg;
	for(i=0; i<arraySize; i++)
	{
		msgrcv(messageID, &binsMsg, sizeof(binsMsg), serverToClient, messageFlag);
		memcpy(bA[i], binsMsg.content, sizeof(bA[i]));
	}
	msgctl(messageID, IPC_RMID, NULL);

	for(i=0; i<arraySize; i++)
	{
		for(j=31; j>=0; j--)
			printf("%d", bA[i][j]);
		printf("\n");
	}
	return 0;
}