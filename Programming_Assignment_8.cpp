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

// header files
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include<string>
using namespace std;

template <class elem_Type>

class list_Type
{
public:
       bool is_Empty() const;
       bool is_Full() const;
       int get_len() const;
       int get_max_Size() const;
       void sort_Alph();
       void print_Result() const;
       void insert_At(const elem_Type& item, int pos);
       list_Type(int listSize = 50);
       ~list_Type();

protected:
       int max_Size;
       int len;
       elem_Type *list;
};

template <class elem_Type>

bool list_Type<elem_Type>::is_Empty() const
{
       return (len == 0);
}

template <class elem_Type>

bool list_Type<elem_Type>::is_Full() const
{
       return (len == max_Size);
}

template <class elem_Type>

int list_Type<elem_Type>::get_len() const
{
       return len;
}

template <class elem_Type>

int list_Type<elem_Type>::get_max_Size() const
{
       return max_Size;
}

template <class elem_Type>

list_Type<elem_Type>::list_Type(int list_Size)
{
       max_Size = list_Size;
       len = 0;
       list = new elem_Type[max_Size];
}

template <class elem_Type>

list_Type<elem_Type>::~list_Type()
{
              delete[] list;
}

template <class elem_Type>

void list_Type<elem_Type>::sort_Alph()
{
       int i, j;
       int min;
       elem_Type temp;

       for (i = 0; i < len; i++)
       {
              min = i;
              for (j = i; j < len; ++j)
                     if (list[j] < list[min])
                           min = j;
              temp = list[i];
              list[i] = list[min];
              list[min] = temp;
       }

}

template <class elem_Type>

void list_Type<elem_Type>::print_Result() const
{
       int i;
       for (i = 0; i < len; ++i)
              cout << list[i];
       cout << endl;
}

template <class elem_Type>

void list_Type<elem_Type>::insert_At(const elem_Type& item, int pos)
{
       assert(pos >= 0 && pos < max_Size);
       list[pos] = item;
       len++;
}

class Stock
{
private:
       string stck_symbol;
       double starting_price;
       double ending_price;
       double today_highPrice;
       double today_lowPrice;
       int Totalnumber_of_shares;
       double previous_ending_price;
       static double total_numberof_assets;
       double percent_gainloss;

public:
       void setStock(string stck_symbol, double starting_price, double ending_price,
        double today_highPrice, double today_lowPrice, int Totalnumber_of_shares,
        double previous_ending_price)
       {
              this->stck_symbol = stck_symbol;
              this->starting_price = starting_price;
              this->ending_price = ending_price;
              this->today_highPrice = today_highPrice;
              this->today_lowPrice = today_lowPrice;
              this->Totalnumber_of_shares = Totalnumber_of_shares;
              this->previous_ending_price = previous_ending_price;
       }

       void print_Result()
       {
              cout << "Stock name: " << stck_symbol << endl;
       }

       void show_different_prices()
       {
        cout << "today's opening price was " << starting_price << ", the closing was" << ending_price << ", today's high was " << today_highPrice << ", today's low was " << today_lowPrice << " Previous closing price is" << previous_ending_price << endl;
       }

       void calculate_gain_loss()
       {
              percent_gainloss = (ending_price - previous_ending_price) /
                  previous_ending_price * 100;
       }

       void show_Totalnumber_of_shares()
       {
              cout << "Number of share(s) is " << Totalnumber_of_shares << endl;
       }

       bool operator> (Stock &cStock)
       {
              return (this->stck_symbol.compare(cStock.stck_symbol)>0);
       }

       bool operator>= (Stock &cStock)
       {
              return (this->stck_symbol.compare(cStock.stck_symbol) >= 0);
       }

       bool operator< (Stock &cStock)
       {
              return (this->stck_symbol.compare(cStock.stck_symbol)<0);
       }

       bool operator<= (Stock &cStock)
       {
              return (this->stck_symbol.compare(cStock.stck_symbol) <= 0);
       }

       bool operator==(Stock &cStock)
       {
              return (this->stck_symbol.compare(cStock.stck_symbol) == 0);
       }

       friend ostream& operator<< (ostream &out, Stock& cStock);

       friend istream& operator>> (istream &in, Stock& cStock);

       static double getTotalAssets()
       {
              return total_numberof_assets;
       }
};

istream& operator>>(istream &in, Stock& cStock)
{
       in >> cStock.stck_symbol;
       in >> cStock.starting_price;
       in >> cStock.ending_price;
       in >> cStock.today_highPrice;
       in >> cStock.today_lowPrice;
       in >> cStock.previous_ending_price;
       in >> cStock.Totalnumber_of_shares;

    cStock.total_numberof_assets+= cStock.Totalnumber_of_shares*cStock.ending_price;

       return in;
}

ostream& operator<< (ostream &out, Stock& cStock)
{
       cStock.calculate_gain_loss();
       out << setw(8) << left << cStock.stck_symbol << right << fixed << setprecision(2) << setw(8) <<
              cStock.starting_price << fixed << setprecision(2) << setw(8) <<
              cStock.ending_price << fixed << setprecision(2) << setw(8) <<
              cStock.today_highPrice << fixed << setprecision(2) << setw(8) <<
              cStock.today_lowPrice << fixed << setprecision(2) << setw(8) <<
              cStock.previous_ending_price << fixed << setprecision(2) << setw(8) <<
              cStock.percent_gainloss << fixed << setprecision(2) << setw(12) <<
              cStock.Totalnumber_of_shares << endl;

       return out;
}

double Stock::total_numberof_assets = 0.0;

// Beginning of main function
int main()
{
       ifstream infile("StockData.txt");
       list_Type<Stock> stock_array(50);
       Stock local_stock;
       int cnt = 0;

       if (!infile)
       {
              cout << "Unable to open file StockData.txt, Program Exiting" << endl; 
              return 0;
       }

       while (!infile.eof())
       {
              infile >> local_stock;
              stock_array.insert_At(local_stock, cnt++);
       }

       stock_array.sort_Alph();

       cout << "**********First Investor's Heaven*************" << endl;
       cout << "*************Financial Report*****************" << endl;
       cout << "Stock              Today                  Previous Percent" << endl;
       cout << "Symbol   Open    Close    High     Low    Close     Gain        Volume" << endl;
       cout << "------   -----   -----    -----    ----- -------- -------      ------" << endl;

       stock_array.print_Result();

       cout << "Closing Assets:$" 
         << fixed << setprecision(2) << Stock::getTotalAssets() << endl;
       cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl;

       system("pause");

       return 0;

}