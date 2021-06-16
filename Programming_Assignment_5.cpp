/* 
#1 on page 890  of C++ Programming. 
Redo Programming Exercise 5 of Chapter 8 using dynamic arrays.

The program prompts a user to enter the number of characters in the string which is stored in a dynamic array of type char. The program then changes all characters in the array to upper case and returns the new string to the user.
*/

// header files
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// function prototypes
void readString(char*, int);
void changeToUppercase(char*, int);
void displayStringInUppercase(char*, int);

// main function
int main() 
{
   // declarations
   int arraySize;
   char* characterArray;

   // prompt user for dynaic array size & allocate memory
   cout << "Enter the size of the dynamic array: ";
   cin >> arraySize;
   characterArray = new char[arraySize];

   // call functions
   readString(characterArray, arraySize);
   changeToUppercase(characterArray, arraySize);
   displayStringInUppercase(characterArray, arraySize);

   // delete dynamic array
   delete[] characterArray;

   system("pause");
   return 0;
}

// readString function
void readString(char* characterArray, int arraySize) 
{
   cout << "Enter a string of " << arraySize << " charaters to be changed:  ";

   for (int i=0; i < arraySize; i++)
      cin >> characterArray[i];
}

// changeToUppercase function
void changeToUppercase (char* characterArray, int arraySize)
{
   for (int i=0; i < arraySize; i++)
      characterArray[i] = toupper(characterArray[i]);
}

// displayStringInUppercase Function
void displayStringInUppercase (char* characterArray, int arraySize)
{
   cout << "\nThe string in upper case letters: ";
   for(int i=0; i < arraySize; i++)
      cout << characterArray[i];
   cout << endl;
}