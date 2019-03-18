/* @desc Write a C program for implementing chat server.
@name Ankit Apurv 180970042
@date 25/02/2019
@desc server
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>	//
#include <sys/socket.h>	//
#include <netinet/in.h>
#include <unistd.h> //close()

int main(void) {
	struct sockaddr_in selfAddress, clientAddress;

	const int flags = 0;
	const int clientQueueSize = 1;

	int socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	selfAddress.sin_family = AF_INET;	//IP family
	selfAddress.sin_port = htons(5300);	//serverPort
	selfAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	bind(socketfd, (struct sockaddr*) &selfAddress, sizeof(struct sockaddr));

	char buf[10] = {'\0'};
	unsigned int bufSize = sizeof(buf);
	unsigned int clientAddressSize = sizeof(clientAddress);

	listen(socketfd, clientQueueSize);
	int clientSocket = accept(socketfd, (struct sockaddr*) &clientAddress, &clientAddressSize);
	
	while(strcmp(buf, "goodbye") != 0) {
		recv(clientSocket, buf, bufSize, flags);
		printf("Received : %s\n", buf);

		size_t i;
		for(i=0; i<bufSize; i++) {
			if(buf[i] >= 65 && buf[i] <= 90)
				buf[i] = buf[i] + 32; //toSmall
			else if(buf[i] >= 97 && buf[i] <= 122)
				buf[i] = buf[i] - 32; //toCapital
		}
		send(clientSocket, buf, bufSize, flags);
		printf("Sent : %s\n\n", buf);
	}
	close(socketfd);
	return 0;
}
