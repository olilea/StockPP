
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

string StockHandler::toPrettyString(list<string> stockTokens) {

	string prettyString = "";

	prettyString += "Ticker:\t\t" + stockTokens.front() + "\r\n";
	stockTokens.pop_front();
	prettyString += "Company Name:\t" + stockTokens.front() + "\r\n";
	stockTokens.pop_front();
	prettyString += "Latest Value:\t$ " + stockTokens.front() + "\r\n";
	stockTokens.pop_front();
	prettyString += "Opening Value:\t$ " + stockTokens.front() + "\r\n";
	stockTokens.pop_front();
	prettyString += "Closing value:\t$ " + stockTokens.front() + "\r\n";

	return prettyString;
}

list<string> StockHandler::lexStockData(string stockData, string ticker) {

	list<string> stockTokens;
	string stockString;
	int stockStringLength;

	string substring = "";

	// Find the end of the received TCP header
	unsigned posOfData = stockData.find("\r\n\r\n");

	// Remove the \r\n\r\n
	posOfData += 4;

	// Creates a new string of everything in stockData from posOfData to the end of the string
	stockString = stockData.substr(posOfData, string::npos);
	stockStringLength = stockString.length();

	for (int i = 0; i < stockStringLength; ++i) {

		substring = "";
		// If a \" is found, retrieve everything until the next \" is found
		if (stockString.at(i) == '\"') {

			i++;
			while (stockString.at(i) != '\"') {
				substring += stockString.at(i++);
			}
			stockTokens.push_back(substring);

		// If the characters found are numbers, retrieve the number and the decimal point
		} else if (stockString.at(i) >= '0' && stockString.at(i) <= '9') {

			// While not at the end of the string and the character currently at is a ',':
			while ((i < stockStringLength) && (stockString.at(i) != ',')) {
				substring += stockString.at(i);
				i++;
			}
			stockTokens.push_back(substring);

		} else {
			continue;
		}
	}

	/*
	for (list<string>::const_iterator y = stockTokens.begin(); y != stockTokens.end(); ++y) {
		cout << *y << " ";
	}
	cout << endl;
	*/

	return stockTokens;
	
}

string StockHandler::getStockData(string ticker) {

	string dataPath = URL_PATH + ticker + URL_SUFFIX;
	string sendString = "GET " + dataPath + " HTTP/1.0\r\nHost: "+ URL_DOMAIN + "\r\n\r\n";

	char recvBuf[1024] = {0};
	//char *sendString.c_str() = new char[sendString.length() + 1];
	//strcpy(sendString.c_str(), sendString.c_str());

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

	write(socketDesc, sendString.c_str(), strlen(sendString.c_str()));

	while (read(socketDesc, recvBuf, sizeof(recvBuf)) > 0);

	close(socketDesc);
	
	return string(recvBuf);
}

bool StockHandler::stockExists(string ticker) {

	list<string> stockTokens = lexStockData(getStockData(ticker), ticker);

	// Pop the ticker and the name
	stockTokens.pop_front();
	stockTokens.pop_front();

	// Latest value is 0.00 only if the stock does not exist
	if (atof(stockTokens.front().c_str()) != 0.00) {
		return true;
	}

	return false;
}
