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

int main(void) {
	struct sockaddr_in selfAddress, clientAddress;

	const int flags = 0;

	int socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	selfAddress.sin_family = AF_INET;	//IP family
	selfAddress.sin_port = htons(5300);	//clientPort
	selfAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	clientAddress.sin_family = AF_INET;	//IP family
	clientAddress.sin_port = htons(5350);	//clientPort
	clientAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	bind(socketfd, (struct sockaddr*) &selfAddress, sizeof(selfAddress));

	char sendBuf[10], recvBuf[10];

	while(strcmp(recvBuf, "goodbye") != 0) {
		recvfrom(socketfd, recvBuf, sizeof(recvBuf), flags, (struct sockaddr*) &clientAddress, sizeof(struct sockaddr));
		printf("Received : %s\n", recvBuf);

		size_t i;
		for(i=0; i<strlen(recvBuf); i++)
			sendBuf[i] = recvBuf[i] - 32; //capitalizing

		sendto(socketfd, sendBuf, sizeof(sendBuf), flags, (struct sockaddr*) &clientAddress, sizeof(struct sockaddr));
		printf("Sent : %s\n\n", sendBuf);
	}
	close(socketfd);
	return 0;
}
