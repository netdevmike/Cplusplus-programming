/* 
Programming Assignment 7
Michael Charara

Write a program that prompts the user to enter a length in feet and inches and outputs the equivalent length in centimeters. 
If the user enters a negative number or a nondigit number, throw and handle an appropriate exception and prompt the user to enter another set of numbers.
*/

// header files
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// function prototype
double getdata(string);

// main fuction
int main ()
{
    double ft,in,cm;
    ft=getdata("feet");
    in=getdata("inches");
    cm=(12.*ft+in)*2.54;
    cout<<ft<<" feet "<<in<<" inches="<<setprecision(2)<<fixed<<cm<<" centimeters\n";
    system("pause");
    return 0;
}

// getData Function
double getdata(string mess)
{
    bool done=false;   
    double n=0;
    string errormessage="input failed";
    do   
    {
        try
        {
            cout<<"Enter value for "<<mess<<": ";
            cin>>n;
            if(cin.fail())   
            throw errormessage;
            if(n<0)
            throw -1;
            done = true;
        }  
        catch(int)
        {
            cout<<"You have entered an invalid value\n";
            n=0;
        }

        catch(string errormessage)
        {
            cout<<errormessage<<"-try again\n";
            cin.clear();   
            cin.ignore(100,'\n');
        }
    }
    while (!done);
    return n;
}