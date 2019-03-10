/* @desc Write a client server program to accept an array of student data and return the results to the client. 
The student details should be a structure data type containing the following elements: 
Registration Number, Student Name and Marks in 3 subjects.
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

//const int countOfSubjects = 3;
#define countOfSubjects 3

struct student {
	int registration;
	char name[10];
	int marks[countOfSubjects];
	int percentage;
};

int main(void)
{
	printf("03 Stuednet Result Client\n");
	struct student s1;

	const int messageFlag = 0;
	const int clientToServer = 1;
	const int serverToClient = 2;

	int i;

	printf("Registration : ");
	scanf("%d", &s1.registration);
	printf("Name : ");
	scanf("%10s", s1.name);
	for(i=0; i<countOfSubjects; i++)
	{
		printf("Subject %d : ", i+1);
		scanf("%d", &s1.marks[i]);
	}
	s1.percentage = 0;

	int messageID = msgget((key_t)50, 0666 | IPC_CREAT);
	struct message m;
	m.type = clientToServer;
	//memcpy(void *dest, const void *src, size_t n);
	memcpy(m.content, &s1, sizeof(struct student));
	msgsnd(messageID, &m, sizeof(m), messageFlag);

	messageID = msgget((key_t)65, 0666 | IPC_CREAT);
	m.type = serverToClient;
	msgrcv(messageID, &m, sizeof(m), serverToClient, messageFlag);
	msgctl(messageID, IPC_RMID, NULL);
	//memcpy(void *dest, const void *src, size_t n);
	memcpy(&s1, m.content, sizeof(struct student));

	printf("Percentage : %d\n", s1.percentage);

	return 0;
}