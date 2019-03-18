/* @desc to calculate gross and net salary calculations on the server as per the client’s input.
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

struct sal {
float salary, da, tax, net, gross;
};

int main(void) {
	struct sockaddr_in selfAddress, clientAddress;
	const int flags = 0;
	int socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	selfAddress.sin_family = AF_INET;	//IP family
	selfAddress.sin_port = htons(5300);	//serverPort
	selfAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	bind(socketfd, (struct sockaddr*) &selfAddress, sizeof(struct sockaddr));

	unsigned int bufSize = sizeof(struct sal);
	unsigned int clientAddressSize = sizeof(clientAddress);
	
	struct sal sal1;
	
	while(true) {
		recvfrom(socketfd, &sal1, bufSize, flags, (struct sockaddr*) &clientAddress, &clientAddressSize);
		printf("Received\n");
		
		sal1.tax = 0.1 * sal1.salary;
		sal1.gross = sal1.salary + sal1.da;
		sal1.net = sal1.gross - sal1.tax;
		
		sendto(socketfd, &sal1, bufSize, flags, (struct sockaddr*) &clientAddress, clientAddressSize);
		printf("Sent\n\n");
	}
	close(socketfd);
	return 0;
}
