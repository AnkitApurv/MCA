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
	const int clientQueueSize = 1;
	int socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	selfAddress.sin_family = AF_INET;	//IP family
	selfAddress.sin_port = htons(5300);	//serverPort
	selfAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	bind(socketfd, (struct sockaddr*) &selfAddress, sizeof(struct sockaddr));

	unsigned int clientAddressSize = sizeof(clientAddress);
	char ping;
	
	listen(socketfd, clientQueueSize);

	while(true) {
		int clientSocket = accept(socketfd, (struct sockaddr*) &clientAddress, &clientAddressSize);
		recv(clientSocket, &ping, sizeof(char), flags);
		printf("Received\n");
		
		time_t serverTime = time(NULL);
		
		send(clientSocket, &serverTime, sizeof(time_t), flags);
		close(clientSocket);
		printf("Sent\n\n");
	}
	close(socketfd);
	return 0;
}
