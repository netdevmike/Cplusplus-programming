/* 
Programming Assignment 8
Michael Charara

(Stock Market) Write a program to help a local stock trading company automate its systems. The company invests only in the stock market. At the end of each trading day, the company would like to generate and post the listing of its stocks so that investors can see how their holdings performed that day. We assume that the company invests in, say, 10 different stocks. The desired output is to produce two listings, one sorted by stock symbol and another sorted by percent gain from highest to lowest. 
The input data is provided in a file in the following format:
symbol openingPrice closingPrice todayHigh todayLow
prevClose volume
For example, the sample data is:
MSMT 112.50 115.75 116.50 111.75 113.50 6723823
CBA 67.50 75.50 78.75 67.50 65.75 378233
-
-
-
The first line indicates that the stock symbol is MSMT, today’s opening
price was 112.50, the closing price was 115.75, today’s high price was
116.50, today’s low price was 111.75, yesterday’s closing price was
113.50, and the number of shares currently being held is 6723823.
The listing sorted by stock symbols must be of the following form:

The listing sorted by stock symbols must be of the following form:
********* First Investor's Heaven **********
********* Financial Report **********
Stock           Today                 Previous Percent
Symbol  Open    Close   High    Low     Close   Gain    Volume
------  -----   -----   -----   ----- -------- -------  ------
ABC     123.45  130.95  132.00  125.00  120.50  8.67%   10000
AOLK    80.00   75.00   82.00   74.00   83.00   -9.64%  5000
CSCO    100.00  102.00  105.00  98.00   101.00  0.99%   25000
IBD     68.00   71.00   72.00   67.00   75.00   -5.33%  15000
MSET    120.00  140.00  145.00  140.00  115.00  21.74%  30920
Closing Assets: $9628300.00
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
Develop this programming exercise in two steps. In the first step (part a), design and implement a stock object. In the second step (part b), design and implement an object to maintain a list of stocks.
a. (Stock Object) Design and implement the stock object. Call the class that captures the various characteristics of a stock object stockType.
The main components of a stock are the stock symbol, stock price, and number of shares. Moreover, we need to output the opening price, closing price, high price, low price, previous price, and the percent gain/loss for the day. These are also all the characteristics of a stock. Therefore, the stock object should store all this
information. Perform the following operations on each stock object:
    i. Set the stock information.
    ii. Print the stock information.
    iii. Show the different prices.
    iv. Calculate and print the percent gain/loss.
    v. Show the number of shares.
        a.1. The natural ordering of the stock list is by stock symbol. Overload the relational operators to compare two stock objects by their symbols.
        a.2. Overload the insertion operator, <<, for easy output.
        a.3. Because the data is stored in a file, overload the stream extraction operator, >>, for easy input.
        For example, suppose infile is an ifstream object and the input file was opened using the object infile. Further suppose that myStock is a stock object. Then, the statement infile >> myStock; reads the data from the input file and stores it in the object myStock. (Note that this statement reads and stores the data in the relevant components
        of myStock.)
b. Now that you have designed and implemented the class stockType to implement a stock object in a program, it is time to create a list of stock objects.
Let us call the class to implement a list of stock objects stockListType.
The class stockListType must be derived from the class listType, which you designed and implemented in the previous exercise. However,the class stockListType is a very specific class, designed to create a list of stock objects. Therefore, the class stockListType is no longer a template.
Add and/or overwrite the operations of the class listType to implement the necessary operations on a stock list.
The following statement derives the class stockListType from the class listType.
class stockListType: public listType<stockType>
{
    member list
};
The member variables to hold the list elements, the length of the list, and the maximum size of the list were declared as protected in the class listType. Therefore, these members can be directly accessed in the
class stockListType. Because the company also requires you to produce the list ordered by the percent gain/loss, you need to sort the stock list by this component. However, you are not to physically sort the list by the component percent gain/loss. Instead, you will provide a logical ordering with respect to this component.
To do so, add a member variable, an array, to hold the indices of the stock list ordered by the component percent gain/loss. Call this array sortIndicesGainLoss. When printing the list ordered by the component percent gain/loss, use the array sortIndicesGainLoss to print the list. The elements of the array sortIndicesGainLoss will tell which component of the stock list to print next.
c. Write a program that uses these two classes to automate the company’s analysis of stock data.
*/

#include "stockApp.h"
#include "stockListType.h"
#include "listType.h"

#include <iostream>

using namespace std;

int main()
{
   stockApp s;

   s.execute();  


   system("PAUSE");
   return 0;
}

stockApp.h

#ifndef STOCK_APP_H
#define STOCK_APP_H

#include "stockListType.h"
#include <regex>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class stockApp
{
public:
   stockApp();

   void execute();
  
private:
   stockListType lst;
   void menu();
   int getSelection(string);
   string changeFileName();
   bool fileExists(const string&);
};

#endif // !STOCK_APP_H


stockApp.cpp

#include "stockApp.h"

stockApp::stockApp() { }

void stockApp::execute()
{
   menu();
}

void stockApp::menu()
{
   char goAgain = ' ';
   int selection;

   if (fileExists(lst.getFileName())) //if the default input file exists, populate the stock object list with the data  
       lst.populateList(); //populate the list with the items in the default input file.

   else //if the default input file does not exist, display a warning message

       cout << "***Warning: the input file " << lst.getFileName() << " does not exist. " << endl <<
       "Please ensure the file is present or enter the name of a new file by selecting option 4 from the main menu." << endl << endl;


   do {

       cout << "*********   First Investor's Heaven   *********" << endl;
       cout << "*******   Financial Reporting Software   *******" << endl << endl;

       cout << "1: Print a stock reports to file" << endl;
       cout << "2: Print a stock report to screen" << endl;
       cout << "3. Print stock report to screen sorted by percentage gain" << endl;
       cout << "4. Change the input file name" << endl;
       cout << "5. Exit" << endl << endl;

       selection = getSelection("Please make a selection"); //get a valid user menu selection

       system("CLS");

       switch (selection) //run the desired function based on user input
       {
       case 1: // create file reports
           lst.createFileReport();
           lst.createFileReportByGainLoss();
           break;
       case 2: //print report to screen
           lst.printScreenReport();
           break;
       case 3: //print report to screen sorted by gain
           lst.printScreenReportByGain();
           break;
       case 4: //change input file name
           lst.clearList();
           lst.setFileName(changeFileName());
           lst.populateList();
           break;
       case 5: //exit
           exit(0);
           break;
       default:
           cout << "An Error has occured, the program will now exit" << endl;
           exit(0);
       }

       cout << endl;
       cout << "Would you like to retun to the menu? y/n" << endl; //ask the user if they want to return to the menu. If not, exit.
       cin >> goAgain;

       system("CLS");

   } while (tolower(goAgain) == 'y'); //end do/while

   system("CLS");
   cout << "The program will now exit" << endl << endl;
}

int stockApp::getSelection(string prompt)
{
   bool valid = false;
   string input;
   regex pattern ("^[+]?[1-5]$");
  
   do
   {
       cout << prompt << endl;
       cin >> input;

       if (!regex_match(input, pattern))
       {
           cout << "This is not a valid selection, please try again" << endl;
       }
       else
           valid = true;
   } while (!valid);

   return stoi(input);
}

string stockApp::changeFileName()
{
   bool valid = false;
   string tempName;
   string defaultFileName = "stocks.txt";
   string currentFileName = lst.getFileName();
   regex pattern("^[A-za-z0-9]+\.txt$");

   cout << "The current file being read is " << currentFileName << ". If you would like to keep using this file, type exit to continue." << endl;
   cout << "If you would like to change this file, enter the name of the new file, including the file extension (must be .txt), and press enter." << endl;
   cout << "If you would like to reset the file name to the default file name of " << defaultFileName << ", type default and press enter." << endl << endl;


   do {
       cout << "Make a selection: ";
       cin >> tempName;
       cout << endl;

       transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);

       if (tempName == "exit")
       {
           tempName = currentFileName;
           cout << "File name was not changed." << endl;
           valid = true;
       }
       else if (tempName == "default")
       {
           tempName = defaultFileName;
           cout << "File name was set to default." << endl;
           valid = true;
       }
       else if (!fileExists(tempName))
       {
           cout << "The file " << tempName << " does not exist. Please try again" << endl << endl;
           valid = false;
       }
       else if (regex_match(tempName, pattern))
       {
           cout << "The file name was changed to " << tempName << endl;
           valid = true;
       }
       else
       {
           cout << "This is not a valid file path. Please only enter files ending in .txt." << endl << "File Name unchanged" << endl << endl;
           valid = false;
       }
   } while (!valid);

   return tempName;
}

bool stockApp::fileExists(const string& fileName)
{
   struct stat buffer;
   return (stat(fileName.c_str(), &buffer) == 0);
}

stockListType.cpp

#include "stockListType.h"

stockListType::stockListType() : listType<stockType>(), totalAssetsValue(0) { }

void stockListType::populateList()
{
   ifstream file;
   file.open(fileName);

   int lines = countLines();
   int i = 0;

   stockType temp;  

   if (file.good() && file.is_open())
   {  
       while (!file.eof() && i < lines)
       {
           file >> temp;
           addToList(temp);
           i++;
       }
   }
   file.close();

   t.sort();
}

int stockListType::countLines()
{
   int lines = 0;
   string s = "";

   ifstream file;
   file.open(fileName);

   if (file.good() && file.is_open())
   {

       while (!file.eof())
       {
           getline(file, s);
           s.erase(remove_if(s.begin(), s.end(), isspace), s.end()); //eliminate all spaces from the read lines

           if (!s.empty())
           {
               lines++;
               s = "";
           }
       }
   }

   return lines;
}

void stockListType::addToList(stockType obj)
{
   t.insertAt(obj, t.getLength());
}

void stockListType::clearList()
{
   t.clear();
}

string stockListType::getFileName()
{
   return this->fileName;
}

double stockListType::getTotalAssetsValue()
{
   stockType temp;
   double totalAssetsValue = 0;

   for (int i = 0; i < t.getLength(); i++)
   {
       temp = t.getAt(i);

       totalAssetsValue += (temp.getNumOfShares() * temp.getClosingPrice());
   }

   return totalAssetsValue;
}

void stockListType::setFileName(string fileName)
{
   this->fileName = fileName;
}

void stockListType::createFileReport()
{  
   ofstream file;
   file.open("Stock Report - By Symbol.txt");
   stockType temp;

   createHeader(file);

   for (int i = 0; i < t.getLength(); i++)
   {
       temp = t.getAt(i);

       file << temp;
   }//end for

   file << "Closing Assets: $" << getTotalAssetsValue() << endl;

   createFooter(file);


   file.flush();
   file.close();

   cout << "Files created sucessfully" << endl;
}

void stockListType::printScreenReport()
{
   stockType temp;

   createHeader(cout);

   for (int i = 0; i < t.getLength(); i++)
   {
       temp = t.getAt(i);

       cout << temp;
   }//end for

   cout << "Closing Assets: $" << getTotalAssetsValue() << endl;

   createFooter(cout);
}

void stockListType::createFileReportByGainLoss() //create a report file from the stock data sorted by gain/loss. By Bill Fulton
{
   ofstream file;
   file.open("Stock Report - By Gain.txt");
   stockType temp;

   int* sortIndicesGainLoss = new int[t.getLength()];

   sortIndicesGainLoss = sortGainLoss(); //create a list of indices for the stock data sorted by percentage gain

   createHeader(file); //create the file header

   for (int i = 0; i < t.getLength(); i++) //iterate over the stock data objects sorted by their gain
   {
       temp = t.getAt(sortIndicesGainLoss[i]);

       file << temp; //output to file using the overloaded stream insertion operator
   }//end for

   file << "Closing Assets: $" << getTotalAssetsValue() << endl; //add the value of all stock assets to the report

   createFooter(file); //create the file footer


   file.flush(); //flush the file stream
   file.close(); //close the file
} //end createFileReportByGainLoss

void stockListType::printScreenReportByGain()
{
   stockType temp;
  
   int* sortIndicesGainLoss = new int[t.getLength()];

   sortIndicesGainLoss = sortGainLoss();

   createHeader(cout);

   for (int i = 0; i < t.getLength(); i++)
   {
       temp = t.getAt(sortIndicesGainLoss[i]);

       cout << temp;
   }//end for  

   cout << "Closing Assets: $" << getTotalAssetsValue() << endl;

   createFooter(cout);
}

void stockListType::createHeader(ostream & file)
{
   file << "*********   First Investor's Heaven   *********" << endl;
   file << "*********      Financial Report        *********" << endl;
   file << "Stock              Today                  Previous Percent" << endl;
   file << "Symbol   Open    Close    High     Low    Close     Gain        Volume" << endl;
   file << "------   -----   -----    -----    ----- -------- -------      ------" << endl;
}

void stockListType::createFooter(ostream & file)
{
   file << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
}

int* stockListType::sortGainLoss()
{
   double min = 0;
   double max;

   int* sortIndicesGainLoss = new int[t.getLength()];

   for (int i = 0; i < t.getLength(); i++)
       sortIndicesGainLoss[i] = i;


   for (int i = 0; i < t.getLength(); i++)
   {
       for (int j = 0; j < t.getLength() - 1; j++)
       {
           if (t.getAt(sortIndicesGainLoss[j]).getPercentGainLoss() < t.getAt(sortIndicesGainLoss[j + 1]).getPercentGainLoss())
           {
               int temp = sortIndicesGainLoss[j];
               sortIndicesGainLoss[j] = sortIndicesGainLoss[j + 1];
               sortIndicesGainLoss[j + 1] = temp;
           }
       }
   }

   return sortIndicesGainLoss;
}

stockListType.h

#ifndef STOCK_LIST_TYPE_H
#define STOCK_LIST_TYPE_H

#include "stockType.h"
#include "listType.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class stockListType : public listType<stockType>
{
public:

   stockListType();
  
   void populateList();
   void clearList();  
  
   string getFileName();
   double getTotalAssetsValue();

   void setFileName(string);

   void createFileReport();
   void createFileReportByGainLoss();
   void printScreenReport();
   void printScreenReportByGain();

private:
   listType<stockType> t;
   double totalAssetsValue;
   string fileName = "stocks.txt";

   void addToList(stockType);
   void createHeader(ostream&);
   void createFooter(ostream&);
   int* sortGainLoss();

   int countLines();  
};
#endif // !STOCK_LIST_TYPE_H

stockType.cpp

#include "stockType.h"

/**************************************************
           Stream Operator Overloads
***************************************************/
ostream& operator<<(ostream& out, stockType& temp)
{
   char tab = '\t';
  
   out.imbue(locale(""));
   out << setprecision(2) << fixed;

   out << temp.getSymbol() << tab << setw(6) << temp.getOpeningPrice() << tab << setw(6) << temp.getClosingPrice() << tab << setw(7) << temp.getHighPrice() << tab << setw(8) << temp.getLowPrice() <<
       setw(8) << temp.getPreviousPrice() << setw(10) << temp.getPercentGainLoss() << "%" << tab << setw(11) << temp.getNumOfShares() << endl;
  
   return out;
}

istream& operator>>(istream& in, stockType& obj)
{
   string temp;
   double val;

   in >> temp;
   obj.setSymbol(temp);

   in >> val;
   obj.setOpeningPrice(val);

   in >> val;
   obj.setClosingPrice(val);

   in >> val;
   obj.setHighPrice(val);

   in >> val;
   obj.setLowPrice(val);

   in >> val;
   obj.setPerviousPrice(val);

   in >> val;
   obj.setNumOfShares(val);  

   return in;
}


/***************************************************
               constructors
****************************************************/
stockType::stockType() { }


/**************************************************
               accessors
**************************************************/
string stockType::getSymbol()
{
   return this->symbol;
}

double stockType::getTotalValue()
{
   this->totalValue = closingPrice * numOfShares;

   return totalValue;
}

int stockType::getNumOfShares()
{
   return this->numOfShares;
}

double stockType::getOpeningPrice()
{
   return this->openingPrice;
}

double stockType::getClosingPrice()
{
   return this->closingPrice;
}

double stockType::getHighPrice()
{
   return this->highPrice;
}

double stockType::getLowPrice()
{
   return this->lowPrice;
}

double stockType::getPreviousPrice()
{
   return this->previousPrice;
}

double stockType::getPercentGainLoss()
{
   percentGainLoss = ((closingPrice - previousPrice) / previousPrice) * 100;

   return percentGainLoss;
}


/**************************************************
               Mutators
***************************************************/
void stockType::setSymbol(string symbol)
{
   this->symbol = symbol;
}

void stockType::setNumOfShares(int numOfShares)
{
   this->numOfShares = numOfShares;
}

void stockType::setOpeningPrice(double openingPrice)
{
   this->openingPrice = openingPrice;
}

void stockType::setClosingPrice(double closingPrice)
{
   this->closingPrice = closingPrice;
}

void stockType::setHighPrice(double highPrice)
{
   this->highPrice = highPrice;
}

void stockType::setLowPrice(double lowPrice)
{
   this->lowPrice = lowPrice;
}

void stockType::setPerviousPrice(double previousPrice)
{
   this->previousPrice = previousPrice;
}


/**************************************************
           Relational Operator Overloads
***************************************************/
bool stockType::operator==(stockType& obj)
{
   return symbol == obj.getSymbol();
}

bool stockType::operator!=(stockType& obj)
{
   return symbol != obj.getSymbol();
}

bool stockType::operator<=(stockType& obj)
{
   return symbol <= obj.getSymbol();
}

bool stockType::operator<(stockType& obj)
{
   return symbol < obj.getSymbol();
}

bool stockType::operator>=(stockType& obj)
{
   return symbol >= obj.getSymbol();
}

bool stockType::operator>(stockType& obj)
{
   return symbol > obj.getSymbol();
}

stockType.h

#ifndef STOCK_TYPE_H
#define STOCK_TYPE_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class stockType
{

   friend ostream& operator<<(ostream&, stockType&);
   friend istream& operator>>(istream&, stockType&);  

public:

   stockType();

   string getSymbol();
   double getTotalValue();
   int getNumOfShares();
   double getOpeningPrice();
   double getClosingPrice();
   double getHighPrice();
   double getLowPrice();
   double getPreviousPrice();
   double getPercentGainLoss();

   void setSymbol(string);
   void setNumOfShares(int);
   void setOpeningPrice(double);
   void setClosingPrice(double);
   void setHighPrice(double);
   void setLowPrice(double);
   void setPerviousPrice(double);

   bool operator== (stockType&);
   bool operator!= (stockType&);
   bool operator<= (stockType&);
   bool operator< (stockType&);
   bool operator>= (stockType&);  
   bool operator> (stockType&);

private:
   string symbol;
   double totalValue;
   int numOfShares;
   double openingPrice;
   double closingPrice;
   double highPrice;
   double lowPrice;
   double previousPrice;
   double percentGainLoss;
};
#endif // !STOCK_TYPE_H

listType.h

#ifndef STOCK_TYPE_H
#define STOCK_TYPE_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class stockType
{

   friend ostream& operator<<(ostream&, stockType&);
   friend istream& operator>>(istream&, stockType&);  

public:

   stockType();

   string getSymbol();
   double getTotalValue();
   int getNumOfShares();
   double getOpeningPrice();
   double getClosingPrice();
   double getHighPrice();
   double getLowPrice();
   double getPreviousPrice();
   double getPercentGainLoss();

   void setSymbol(string);
   void setNumOfShares(int);
   void setOpeningPrice(double);
   void setClosingPrice(double);
   void setHighPrice(double);
   void setLowPrice(double);
   void setPerviousPrice(double);

   bool operator== (stockType&);
   bool operator!= (stockType&);
   bool operator<= (stockType&);
   bool operator< (stockType&);
   bool operator>= (stockType&);  
   bool operator> (stockType&);

private:
   string symbol;
   double totalValue;
   int numOfShares;
   double openingPrice;
   double closingPrice;
   double highPrice;
   double lowPrice;
   double previousPrice;
   double percentGainLoss;
};
#endif // !STOCK_TYPE_H

stocks.txt

ABC 123.45 130.95 132.00 125.00 120.50 10000
MSET 120.00 140.00 145.00 140.00 115.00 30920
AOLK 80 75 82 74 83 5000
CSCO 100 102 105 98 101 25000
IBD 68 71 72 67 75 15000