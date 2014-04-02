#ifndef STOCKHANDLER_H
#define STOCKHANDLER_H

#include <string>
#include <list>

using std::string;
using std::list;

#define URL_DOMAIN "download.finance.yahoo.com"
#define URL_PATH "/d/quotes.csv?s="
#define URL_SUFFIX "&f=snl1op&e=.csv"

class StockHandler {
	
public:

	static string toPrettyString(list<string> stockTokens);
	static list<string> lexStockData(string stockString, string ticker);
	static string getStockData(string ticker);
	static bool stockExists(string ticker);
};

#endif
