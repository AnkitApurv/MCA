/* @desc to perform basic arithmetic operations in Client Server mode.
@name Ankit Apurv 180970042
@date 11/03/2019
@desc server
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>	//
#include <sys/socket.h>	//
#include <netinet/in.h>
#include <unistd.h> //close()
#include <stdbool.h>

struct ops {
	int op1, op2, operator, result;
};

int main(void) {
	struct sockaddr_in selfAddress, clientAddress;
	const int flags = 0;
	const int clientQueueSize = 1;
	int socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	selfAddress.sin_family = AF_INET;	//IP family
	selfAddress.sin_port = htons(5300);	//serverPort
	selfAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	bind(socketfd, (struct sockaddr*) &selfAddress, sizeof(struct sockaddr));

	unsigned int bufSize = sizeof(struct ops);
	unsigned int clientAddressSize = sizeof(clientAddress);
	
	struct ops work;

	listen(socketfd, clientQueueSize);
	
	while(true) {
		int clientSocket = accept(socketfd, (struct sockaddr*) &clientAddress, &clientAddressSize);

		recv(clientSocket, &work, bufSize, flags);
		printf("Received\n");
		
		switch(work.operator)
		{
		case 1:
			work.result = work.op1/work.op2;
			break;
		case 2:
			work.result = work.op1*work.op2;
			break;
		case 3:
			work.result = work.op1+work.op2;
			break;
		case 4:
			work.result = work.op1-work.op2;
			break;
		default:
			work.result=0;
		}
		
		send(clientSocket, &work, bufSize, flags);
		printf("Sent\n\n");
	}
	close(socketfd);
	return 0;
}
