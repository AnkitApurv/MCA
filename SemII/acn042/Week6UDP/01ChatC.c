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

int main(void) {
	struct sockaddr_in selfAddress, serverAddress;

	const int flags = 0;

	int socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	selfAddress.sin_family = AF_INET;	//IP family
	selfAddress.sin_port = htons(5350);	//clientPort
	selfAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	serverAddress.sin_family = AF_INET;	//IP family
	serverAddress.sin_port = htons(5300);	//clientPort
	serverAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	bind(socketfd, (struct sockaddr*) &selfAddress, sizeof(selfAddress));

	char sendBuf[10], recvBuf[10];
	int sendBufSize;

	while(strcmp(sendBuf, "goodbye") != 0) {
		printf("To Send : ");
		fgets(sendBuf, 10, stdin);
		sendBufSize = strlen(sendBuf);
		if((sendBufSize > 0) && (sendBuf[sendBufSize] == '\n'))
			sendBuf[sendBufSize] = '\0';
		sendto(socketfd, sendBuf, sendBufSize, flags, (struct sockaddr*) &serverAddress, sizeof(struct sockaddr));

		recvfrom(socketfd, recvBuf, sizeof(recvBuf), flags, (struct sockaddr*) &serverAddress, sizeof(struct sockaddr));
		printf("Received : %s\n\n", recvBuf);
	}
	close(socketfd);
	return 0;
}
