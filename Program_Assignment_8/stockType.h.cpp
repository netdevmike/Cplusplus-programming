#ifndef H_stockType
#define H_stockType

#include <iostream>//include for input-output stream library
#include <fstream>//include for file stream library
#include <iomanip>//include for io manipulation library
#include<string> //include for string library

using namespace std;

class stockType // Declaring Stock Type Class
{
   friend ostream& operator<< (ostream&, const stockType&);
   friend ifstream& operator>> (ifstream&, stockType&);

public:
   void setStockInfo(string symbol, double openPrice,
                      double closeProce, double high,
                      double Low, double prevClose,
                      int   shares);
   string getSymbol();
   double getPercentChange();
   double getOpenPrice();
   double getClosePrice();
   double getHighPrice();
   double getLowPrice();
   double getPrevPrice();
   int getnoOfShares();

   stockType();
   stockType(string symbol, double openPrice,
              double closeProce, double high,
              double Low, double prevClose,
              int   shares);

   bool operator ==(const stockType& other) const;
   bool operator !=(const stockType& other) const;
   bool operator <=(const stockType& other) const;
   bool operator >=(const stockType& other) const;
   bool operator >(const stockType& other) const;
   bool operator <(const stockType& other) const;

private:
   string   stockSymbol;
   double   todayOpenPrice;
   double   todayClosePrice;
   double   todayHigh;
   double   todayLow;
   double   yesterdayClose;
   double   percentChange;
   int       noOfShares;
};

void stockType::setStockInfo(string symbol, double openPrice,//Setting Stock Info Method
                      double closeProce, double high,
                      double low, double prevClose,
                      int   shares)
{
       stockSymbol = symbol;
       todayOpenPrice = openPrice;
       todayClosePrice = closeProce;
       todayHigh = high;
       todayLow = low;
       yesterdayClose = prevClose;
       percentChange = (todayClosePrice - yesterdayClose) / yesterdayClose;
       noOfShares = shares;
}

string stockType::getSymbol() // Method for reterieving symbol
{
   return stockSymbol;
}

double stockType::getPercentChange()// Method for reterieving percenatge change
{
   return percentChange;
}

double stockType::getOpenPrice()// Method for reterieving open price
{
   return todayOpenPrice;
}

double stockType::getClosePrice()// Method for reterieving close price
{
   return todayClosePrice;
}

double stockType::getHighPrice()// Method for reterieving high Price
{
   return todayHigh;
}

double stockType::getLowPrice()// Method for reterieving low price
{
   return todayLow;
}

double stockType::getPrevPrice()// Method for reterieving prev price
{
   return yesterdayClose;
}

int stockType::getnoOfShares()// Method for reterieving no of shares
{
   return noOfShares;
}

stockType::stockType()// Method for setting an empty object for soritng purposes
{
    stockSymbol = "";
    todayOpenPrice = 0;
    todayClosePrice = 0;
    todayHigh = 0;
    todayLow = 0;
    yesterdayClose = 0;
    percentChange = 0;
    noOfShares = 0;
}

stockType::stockType(string symbol, double openPrice,// Method for writng data in to the object
              double closeProce, double high,
              double low, double prevClose,
              int   shares)
{
   stockSymbol = symbol;
   todayOpenPrice = openPrice;
   todayClosePrice = closeProce;
   todayHigh = high;
   todayLow = low;
   yesterdayClose = prevClose;
   percentChange = (todayClosePrice - yesterdayClose) / yesterdayClose; // Percentage change calculation
   noOfShares = shares;
}

bool stockType::operator ==(const stockType& other) const // Natural Logical Sorting Method for data sorting by Symbol
{
   return (stockSymbol == other.stockSymbol);
}

bool stockType::operator !=(const stockType& other) const
{
   return (stockSymbol != other.stockSymbol);
}

bool stockType::operator <=(const stockType& other) const
{
   return (stockSymbol <= other.stockSymbol);
}

bool stockType::operator >=(const stockType& other) const
{
   return (stockSymbol >= other.stockSymbol);
}

bool stockType::operator >(const stockType& other) const
{
   return (stockSymbol > other.stockSymbol);
}

bool stockType::operator <(const stockType& other) const
{
   return (stockSymbol < other.stockSymbol);
}

ostream& operator<<(ostream& os, const stockType& stock) // Out stream simplification
{
   os << setw(6) << stock.stockSymbol << " "
        << setw(6) << stock.todayOpenPrice << " "
       << setw(6) << stock.todayClosePrice << " "
       << setw(6) << stock.todayHigh << " "
       << setw(6) << stock.todayLow << " "
       << setw(6) << stock.yesterdayClose << " "
       << setw(8) << stock.percentChange * 100 << "% "
       << setw(10) << stock.noOfShares;
   return os;
}

ifstream& operator>> (ifstream& inf, stockType& stock)// in stream simplification
{
   inf >> stock.stockSymbol >> stock.todayOpenPrice
       >> stock.todayClosePrice >> stock.todayHigh
       >> stock.todayLow >> stock.yesterdayClose
       >> stock.noOfShares;

   stock.percentChange = (stock.todayClosePrice - stock.yesterdayClose) / stock.yesterdayClose;

   return inf;
}

#endif