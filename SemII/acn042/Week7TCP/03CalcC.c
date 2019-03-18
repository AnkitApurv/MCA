/* @desc to perform basic arithmetic operations in Client Server mode.
@name Ankit Apurv 180970042
@date 11/03/2019
@desc client
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>	//
#include <sys/socket.h>	//
#include <netinet/in.h>
#include <unistd.h> //close()

struct ops {
	int op1, op2, operator, result;
};


int main(void) {
	struct sockaddr_in selfAddress, serverAddress;
	const int flags = 0;
	int socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	serverAddress.sin_family = AF_INET;	//IP family
	serverAddress.sin_port = htons(5300);	//serverPort
	serverAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	selfAddress.sin_family = AF_INET;	//IP family
	selfAddress.sin_port = htons(5350);	//clientPort
	selfAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	bind(socketfd, (struct sockaddr*) &selfAddress, sizeof(struct sockaddr));

	struct ops work;
	printf("a : ");
	scanf("%d", &work.op1);
	printf("b : ");
	scanf("%d", &work.op2);
	printf("\nOperations \n 1.Division \n 2.Multiplication \n 3.Addition \n 4.Substraction \n Choice(int) : ");
	scanf("%d", &work.operator);

	unsigned int bufSize = sizeof(struct ops);
	
	connect(socketfd, (struct sockaddr*) &serverAddress, sizeof(struct sockaddr));

	send(socketfd, &work, bufSize, flags);

	recv(socketfd, &work, bufSize, flags);
	
	printf("Result : %d\n", work.result);

	close(socketfd);
	return 0;
}
