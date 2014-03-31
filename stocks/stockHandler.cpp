
#include "stockHandler.h"

#include <string>
#include <list>
#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

using std::string;
using std::strcpy;
using std::list;

using std::cout;
using std::endl;

string StockHandler::toPrettyString(list<string> stockData) {

	// TODO
}

list<string> StockHandler::parseStockData(string stockData) {

	// TODO
}

string StockHandler::getStockData(string ticker) {

	string dataPath = URL_PATH + ticker + URL_SUFFIX;
	string sendString = "GET " + dataPath + " HTTP/1.0\r\n\r\n";

	char *recvBuf = new char[1024];
	char *sendBuf = new char[sendString.length() + 1];
	strcpy(sendBuf, sendString.c_str());

	int socketDesc, c;

	struct hostent *host = gethostbyname(URL_DOMAIN);

	// The relavent struct for connect()
	struct sockaddr_in servAddr;

	/* AF_INET is used for IPv4 addresses
	SOCK_STREAM specifies a reliable transport layer protocol (TCP)
	Third argument left zero for kernel to decide protocol (default TCP) */

	socketDesc = socket(AF_INET, SOCK_STREAM, 0);
	if (socketDesc == -1) {
		perror("Creating socket");
	} // Else returns socket desriptor

	// Type of socket created in socket()
	servAddr.sin_family = AF_INET;

	servAddr.sin_addr.s_addr = *host->h_addr_list[0];

	/* htons() converts the the portnumber from host byte order
	to network byte order */
	servAddr.sin_port = htons(80);

	memset(servAddr.sin_zero, '\0', sizeof servAddr.sin_zero);

	c = connect(socketDesc, (struct sockaddr *)&servAddr, sizeof(servAddr));

	while (c < 0) {
		cout << "Failed to connect to server - retrying..." << endl;
		sleep(5);
		c = connect(socketDesc, (struct sockaddr *)&servAddr, sizeof(servAddr));
	}

	send(socketDesc, sendBuf, strlen(sendBuf), 0);

	int bytesRead = read(socketDesc, recvBuf, sizeof(recvBuf));

	cout << recvBuf;

	delete recvBuf;
	delete sendBuf;
	
}

bool StockHandler::stockExists(string ticker) {

	// TODO
}
