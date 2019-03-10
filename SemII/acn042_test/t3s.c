#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
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
	int i=0;
	struct message m;
	
	int messageID = msgget((key_t)50, 0666 | IPC_CREAT);
	msgrcv(messageID, &m, sizeof(m), clientToServer, messageFlag);
	msgctl(messageID, IPC_RMID, NULL);
	memcpy(s, m.content, sizeof(s));
	printf("recieved");
	while(i<20)
	{
	    if(s[i] != ' ' || s[i] != '\0' || s[i] != '\n')
	        s[i] += 3;
	    i++;
	}
	printf("send");
	m.type = serverToClient;
	memcpy(m.content, s, sizeof(s));
	messageID = msgget((key_t)50, 0666 | IPC_CREAT);
	msgsnd(messageID, &m, sizeof(m), messageFlag);
	printf("sent");
	msgctl(messageID, IPC_RMID, NULL);
	
	printf("Modified : ");
	printf("%s\n", s);
}

	
