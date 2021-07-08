#ifndef H_stockList
#define H_stockList

#include <vector>//include for vector library
#include<string> //include for string library
#include <iostream>//include for input-output stream library
#include<algorithm>//include for algorithm library
#include "stockType.h"// Include to use stock type object

using namespace std;

class stockList // StockList class declaration
{
public:
   void printBySymbol();
   void printByGain();
   void printReports();
   void sortStockList();
   void sortByGain();
  
   void insert(const stockType& item);
private:
   vector<int>   indexByGain;
   vector<stockType> list; // Stock list creation using stock type object
};

void stockList::printBySymbol() // Printing Stock List by Symbol
{
    double closingBalance = 0;
  
    cout << "\n**********************FIRST INVESTORS HEAVEN**********************" << endl;
    cout << "**************************FINANCIAL REPORT*************************" << endl;
    cout << "\nSTOCK           TODAY                    PREVIOUS PERCENT" << endl;
    cout << "SYMBOL OPEN    CLOSE   HIGH    LOW     CLOSE     GAIN          VOLUME" << endl;
    cout << "------ -----   -----   -----   -----   -------- -------     ------" << endl;
    int x=list.size();
    int y=0;
    while (y<x)
    {

        cout << list[y] << endl;
        closingBalance += list[y].getClosePrice() * list[y].getnoOfShares();
        y++;
    }
    cout << "\n*********************************************************************" << endl;
    cout << "CLOSING ASSETS: $" << closingBalance << endl;
    cout << "*********************************************************************" << endl;
}

void stockList::printByGain() // Printing Stock List by Gain
{
    cout << "\n******************    FIRST INVESTORS HEAVEN    ******************" << endl;
    cout << "**********************    FINANCIAL REPORT    *********************" << endl;
    cout << "**********************       GAIN/LOSS       **********************" << endl;
    cout << "\nSTOCK           TODAY                    PREVIOUS PERCENT" << endl;
    cout << "SYMBOL OPEN    CLOSE   HIGH    LOW     CLOSE     GAIN          VOLUME" << endl;
    cout << "------ -----   -----   -----   -----   -------- -------     ------" << endl;

    int x=list.size();
        int y=0;
        while (y<x)
        {
        cout << list[indexByGain[y]]<<"\n";
        y++;
        }
        cout << "******************************************************************" << endl;

}


void stockList::sortStockList() // Sorting stock list by Symbol
{
    sort(list.begin(), list.end());
  
    sortByGain();
}
void stockList::insert(const stockType& item)// ethod for inserting stock type object in stock list
{
    list.push_back(item);
}

void stockList::sortByGain() // Sorting stock List By Gain
{
    bool *temp;
    temp = new bool[list.size()];
    int maxIndex;
    int l=list.size();
    int y=0;
    while(y<l)
    {
        temp[y] = false;
        y++;
    }
    l=list.size();
    int r=0;
    while(r<l)
    {
        l=list.size();
        int j=0;
        while(j<l)
        {
            if (!temp[j])
            {
                maxIndex = j;
                break;
            }
            j++;
        }
        l=list.size();
        j=maxIndex+1;
        while(j<l)
        {
            if (!temp[j])
            {
                if (list[maxIndex].getPercentChange() < list[j].getPercentChange())
                    maxIndex = j;
            }
            j++;
        }
        indexByGain.push_back(maxIndex);
        temp[maxIndex] = true;
        r++;
    }
  
    delete [] temp;
}

#endif