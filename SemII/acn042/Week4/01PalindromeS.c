/* @desc Write a client server program using message queue to check for string palindrome as per the input given by the client.
@name Ankit Apurv 180970042
@date 04/02/2019
@desc server
*/

#include <stdio.h>
#include <stdbool.h>
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
	printf("01 Palindrome Server\n");
	char s1[10] = {'\0'};
	int i, length;

	const int messageFlag = 0;
	const int clientToServer = 1;
	const int serverToClient = 2;

	//printf("Word size : ");
	int messageID = msgget((key_t)40, 0666 | IPC_CREAT);
	if(messageID == -1) return -1;
	struct message lengthMessage;
	msgrcv(messageID, &lengthMessage, sizeof(lengthMessage), clientToServer, messageFlag);
	msgctl(messageID, IPC_RMID, NULL);
	//memcpy(void *dest, const void *src, size_t n);
	//length = lengthMessage.content;
	memcpy(&length, lengthMessage.content, sizeof(int));
	printf("%d\n", length);

	//printf("Input string : \n");
	messageID = msgget((key_t)40, 0666 | IPC_CREAT);
	if(messageID == -1) return -1;
	struct message strMessage;
	msgrcv(messageID, &strMessage, sizeof(strMessage), clientToServer, messageFlag);
	msgctl(messageID, IPC_RMID, NULL);
	//s1 = strMessage.content;
	memcpy(s1, strMessage.content, sizeof(s1));
	printf("%s\n", s1);
	
	int isP = 0;
	for(i=0; i<length; i++)
	{
		if(s1[i] != s1[(length-1) - i])
		{
			isP = -1;
			break;
		}
	}
	printf("%d\n", isP);
	messageID = msgget((key_t)45, 0666 | IPC_CREAT);
	if(messageID == -1) return -1;
	struct message boolMessage;
	boolMessage.type = serverToClient;
	memcpy(boolMessage.content, &isP, sizeof(int));
	//boolMessage.content = isP;
	msgsnd(messageID, &boolMessage, sizeof(boolMessage), messageFlag);

	return 0;
}
