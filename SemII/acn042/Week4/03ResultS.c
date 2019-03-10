/* @desc Write a client server program to accept an array of student data and return the results to the client. 
The student details should be a structure data type containing the following elements: 
Registration Number, Student Name and Marks in 3 subjects.
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
	printf("03 Stuednet Result Server\n");
	struct student s1;

	const int messageFlag = 0;
	const int clientToServer = 1;
	const int serverToClient = 2;

	int messageID = msgget((key_t)50, 0666 | IPC_CREAT);
	struct message m;
	msgrcv(messageID, &m, sizeof(m), clientToServer, messageFlag);
	msgctl(messageID, IPC_RMID, NULL);
	//memcpy(void *dest, const void *src, size_t n);
	memcpy(&s1, m.content, sizeof(struct student));

	printf("%s", s1.name);

	int i, total = 0;
	for(i=0; i<countOfSubjects; i++)
		total += s1.marks[i];
	s1.percentage = total/countOfSubjects;

	printf("%d", s1.percentage);

	messageID = msgget((key_t)65, 0666 | IPC_CREAT);
	m.type = serverToClient;
	//memcpy(void *dest, const void *src, size_t n);
	memcpy(m.content, &s1, sizeof(struct student));
	msgsnd(messageID, &m, sizeof(m), messageFlag);

	return 0;
}