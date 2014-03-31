
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
	string sendString = "GET " + dataPath + " HTTP/1.1\r\nHost: www.finance.yahoo.com\r\n";

	char recvBuf[1024*1024] = {0};
	char *sendBuf = new char[sendString.length() + 1];
	strcpy(sendBuf, sendString.c_str());

	int socketDesc, c;

	struct hostent *host = gethostbyname(URL_DOMAIN);

	// The relavent struct for connect()
	struct sockaddr_in servaddr;

	/* AF_INET is used for IPv4 addresses
	SOCK_STREAM specifies a reliable transport layer protocol (TCP)
	Third argument left zero for kernel to decide protocol (default TCP) */

	socketDesc = socket(AF_INET, SOCK_STREAM, 0);
	if (socketDesc == -1) {
		perror("Creating socket");
	} // Else returns socket desriptor

	// Type of socket created in socket()
	servaddr.sin_family = AF_INET;

	memcpy((char *)&servaddr.sin_addr.s_addr, (char *)host->h_addr_list[0], host->h_length);

	/* htons() converts the the portnumber from host byte order
	to network byte order */
	servaddr.sin_port = htons(80);

	memset(servaddr.sin_zero, '\0', sizeof servaddr.sin_zero);

	c = connect(socketDesc, (struct sockaddr *)&servaddr, sizeof(servaddr));

	while (c < 0) {
		cout << "Failed to connect to server - retrying..." << endl;
		sleep(5);
		c = connect(socketDesc, (struct sockaddr *)&servaddr, sizeof(servaddr));
	}

	cout << "Connected to Yahoo! server...";

	write(socketDesc, sendBuf, strlen(sendBuf));

	while (read(socketDesc, recvBuf, sizeof(recvBuf)) > 0) {
		cout << recvBuf;
	}

	delete sendBuf;
	
}

bool StockHandler::stockExists(string ticker) {

	// TODO
}
