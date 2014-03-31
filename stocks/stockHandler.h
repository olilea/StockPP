#ifndef STOCKHANDLER_H
#define STOCKHANDLER_H

#include <string>
#include <list>

using std::string;
using std::list;

#define URL_DOMAIN "finance.yahoo.com"
#define URL_PATH "/d/quotes.csv?s="
#define URL_SUFFIX "&f=snl1op&e=.csv"

class StockHandler {
	
public:

	static string toPrettyString(list<string> stockData);
	static list<string> parseStockData(string stockString);
	static string getStockData(string ticker);
	static bool stockExists(string ticker);
};

#endif
