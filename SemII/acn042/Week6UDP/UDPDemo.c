#include <stdio.h>
#include <string.h>
#include <sys/types.h>	//
#include <sys/socket.h>	//
#include <netinet/in.h>

int main(void) {
	struct sockaddr_in selfAddress, serverAddress;

	int socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	selfAddress.sin_family = AF_INET;	//IP family
	selfAddress.sin_port = htons(5350);	//clientPort
	selfAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	serverAddress.sin_family = AF_INET;	//IP family
	serverAddress.sin_port = htons(5300);	//clientPort
	serverAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	int status = bind(socket, (struct sockaddr*) &selfAddress, sizeof(selfAddress));

	int bytesTransmitted = sendto(socket, msg, sizeof(msg), flags, (struct sockaddr*) &serverAddress, sizeof(serverAddress));

	bytesTransmitted = recvfrom(socket, recvBuf, sizeof(recvBuf), flags, (struct sockaddr*) &serverAddress, sizeof(serverAddress));

	status = close(socket);

	return 0;
}