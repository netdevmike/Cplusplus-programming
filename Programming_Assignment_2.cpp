/*
Chapter 5 - Exercise 4
 
To make telephone numbers easier to remember, some companies use letters to show their telephone number. For example, using letters, the telephone number 438-5626 can be shown as GET LOAN. In some cases, to make a telephone number meaningful, companies might use more than seven letters. For example, 225-5466 can be displayed as CALL HOME,whichuseseightletters.Writeaprogramthatpromptsthe user to enter a telephone number expressed in letters and outputs the corresponding telephone number in digits. If the user enters more than seven letters, then process only the first seven letters. Also output the - (hyphen) after the third digit. Allow the user to use both uppercase and lowercase letters as well as spaces between words. Moreover, your program should process as many telephone numbers as the user wants. 
 */

// Declare header files.
#include <iostream>
#include <string>
using namespace std;

// start the main function
int main()
{
    // Declare integer
    string letter;
    int count = 0;

    // Display the info on console.
    cout << "Program to prompt the user to enter a telephone number expressed in letters" << endl;
    cout << "To stop the program enter #." << endl;

    // beginning of while loop which will check whether the string contains # or not.
    while (letter != "#")
    {
        // Prompt user to enter the phone number expressed in letters
        cout << "Enter a telephone number expressed in letters: ";

        // input letters.
        getline(cin, letter);
        cout << endl;

        // Display the statement on console.
        cout << "The telephone you entered is: " << letter << endl;

        // Display the telephone number.
        cout << "The corresponding telephone digit is: ";
        int i = 0;

        // beginning of while loop.
        while (i < letter.length())
        {
            // Declare variables.
            bool notSpace = true;

            // Start of switch case
            switch (letter[i])
            {
                // Compare letters
            case 'A':
            case 'a':
            case 'B':
            case 'b':
            case 'C':
            case 'c':
                // Display statement.
                cout << "2";
                // Update count.
                count++;
                break;
                // Compare letters
            case 'D':
            case 'd':
            case 'E':
            case 'e':
            case 'F':
            case 'f':
                // Display statement.
                cout << "3";
                // Update count.
                count++;
                break;
            case 'G':
            case 'g':
            case 'H':
            case 'h':
            case 'I':
            case 'i':
                // Display statement.
                cout << "4";
                // Update count.
                count++;
                break;
            case 'J':
            case 'j':
            case 'K':
            case 'k':
            case 'L':
            case 'l':
                // Display statement.
                cout << "5";
                // Update count.
                count++;
                break;
            case 'M':
            case 'm':
            case 'N':
            case 'n':
            case 'O':
            case 'o':
                // Display statement.
                cout << "6";
                // Update count.
                count++;
                break;
            case 'P':
            case 'p':
            case 'Q':
            case 'q':
            case 'R':
            case 'r':
            case 'S':
            case 's':
                // Display statement.
                cout << "7";
                // Update count.
                count++;
                break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
            case 'V':
            case 'v':
                // Display statement.
                cout << "8";
                // Update count.
                count++;
                break;
            case 'W':
            case 'w':
            case 'X':
            case 'x':
            case 'Y':
            case 'y':
            case 'Z':
            case 'z':
                // Display statement.
                cout << "9";
                // Update count.
                count++;
                break;
            case ' ':
                notSpace = false;
                break;
            default:
                cout << "Invalid input.";
            }

            //display after thrid digit
            if (count == 3 && notSpace)
                // Display hyphen on console.
                cout << "-";
            // Check if value of count is equal to 7 or not.
            if (count == 7)
                break;
            // Update value of i.
            i++;
        }

        cout << endl;
        // Update value of count.
        count = 0;
    }
    system("pause");
    return 0;
}