/* @desc to Implement a day time client and day time server using UDP.
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

#include <time.h>


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

	char ping = '\0';
	time_t serverTime;
	connect(socketfd, (struct sockaddr*) &serverAddress, sizeof(struct sockaddr));

	send(socketfd, &ping, sizeof(char), flags);

	recv(socketfd, &serverTime, sizeof(time_t), flags);
	char* sT = ctime(&serverTime);
	
	printf("Server's Time : %s\n", sT);

	close(socketfd);
	return 0;
}
