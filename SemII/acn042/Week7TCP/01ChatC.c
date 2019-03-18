/* @desc Write a C program for implementing chat server.
@name Ankit Apurv 180970042
@date 25/02/2019
@desc client
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>	//
#include <sys/socket.h>	//
#include <netinet/in.h>
#include <unistd.h> //close()

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

	char buf[10];
	unsigned int bufSize;

	connect(socketfd, (struct sockaddr*) &serverAddress, sizeof(struct sockaddr));

	while(strcmp(buf, "goodbye") != 0) {
		printf("To Send : ");
		fgets(buf, 10, stdin);
		bufSize = strlen(buf);
		
		if((bufSize > 0) && (buf[bufSize] == '\n'))
			buf[bufSize] = '\0';
		send(socketfd, buf, bufSize, flags);

		recv(socketfd, buf, bufSize, flags);
		printf("Received : %s\n\n", buf);
	}
	close(socketfd);
	return 0;
}
