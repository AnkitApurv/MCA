/* @desc to Implement a day time client and day time server using UDP.
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
#include <time.h>

int main(void) {
	struct sockaddr_in selfAddress, clientAddress;
	const int flags = 0;
	int socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	selfAddress.sin_family = AF_INET;	//IP family
	selfAddress.sin_port = htons(5300);	//serverPort
	selfAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	bind(socketfd, (struct sockaddr*) &selfAddress, sizeof(struct sockaddr));

	unsigned int clientAddressSize = sizeof(clientAddress);
	char ping;
	
	while(true) {
		recvfrom(socketfd, &ping, sizeof(char), flags, (struct sockaddr*) &clientAddress, &clientAddressSize);
		printf("Received\n");
		
		time_t serverTime = time(NULL);
		
		sendto(socketfd, &serverTime, sizeof(time_t), flags, (struct sockaddr*) &clientAddress, clientAddressSize);
		printf("Sent\n\n");
	}
	close(socketfd);
	return 0;
}
