#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#include<stdlib.h>
const int messageFlag = 0;
	const int clientToServer = 1;
	const int serverToClient = 2;
struct message {
	long type;
	char content[100];
};

int main(void)
{
    

	
    char s[20];
    int cOS=0;
    int cOC=0;
	int i=0;

	printf("String : ");
	scanf("%s", s);
	
	while(s[i]!='\0' || i<20)
	{
	    if(s[i] == ' ')
	        cOS++;
	    cOC++;
	    i++;
	}
	
	if(!(cOS <1 || cOC < 10))
	{
	    printf("message too short!\n");
	    exit(0);
	}
	
	struct message m;
	m.type = clientToServer;
	memcpy(m.content, s, sizeof(s));
	int messageID = msgget((key_t)50, 0666 | IPC_CREAT);
	msgsnd(messageID, &m, sizeof(m), messageFlag);
	printf("sent");
	msgctl(messageID, IPC_RMID, NULL);
	
	messageID = msgget((key_t)50, 0666 | IPC_CREAT);
	msgrcv(messageID, &m, sizeof(m), serverToClient, messageFlag);
	memcpy(s, m.content, sizeof(s));
	msgctl(messageID, IPC_RMID, NULL);
	printf("recieved");
	
	printf("Modified : ");
	printf("%s\n", s);
}

	
