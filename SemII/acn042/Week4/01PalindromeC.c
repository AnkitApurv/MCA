/* @desc Write a client server program using message queue to check for string palindrome as per the input given by the client.
@name Ankit Apurv 180970042
@date 04/02/2019
@desc client
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
	int length;

	const int messageFlag = 0;
	const int clientToServer = 1;
	const int serverToClient = 2;

	printf("Word size : ");
	scanf("%d", &length);
	int messageID = msgget((key_t)40, 0666 | IPC_CREAT);
	if(messageID == -1) return -1;
	struct message lengthMessage;
	lengthMessage.type = clientToServer;
	//memcpy(void *dest, const void *src, size_t n);
	memcpy(lengthMessage.content, &length, sizeof(int));
	//lengthMessage.content = length;
	msgsnd(messageID, &lengthMessage, sizeof(lengthMessage), messageFlag);


	printf("Input string : \n");
	scanf("%s", s1);
	messageID = msgget((key_t)40, 0666 | IPC_CREAT);
	if(messageID == -1) return -1;
	struct message strMessage;
	strMessage.type = clientToServer;
	memcpy(strMessage.content, s1, sizeof(s1));
	//strMessage.content = s1;
	msgsnd(messageID, &strMessage, sizeof(strMessage), messageFlag);

	int isP = -1;
	messageID = msgget((key_t)45, 0666 | IPC_CREAT);
	if(messageID == -1) return -1;
	struct message boolMessage;
	msgrcv(messageID, &boolMessage, sizeof(boolMessage), serverToClient, messageFlag);
	msgctl(messageID, IPC_RMID, NULL);
	memcpy(&isP, boolMessage.content, sizeof(int));
	//isP = boolMessage.content;
	printf("%d\n", isP);
	if(isP == 0)
		printf("%s is palindrome.\n", s1);
	else if(isP == -1)
		printf("%s is not palindrome.\n", s1);
	return 0;
}