/*
Three employees in a company are up for a special pay increase. You are
given a file, say Ch3_Ex7Data.txt , with the following data:
Miller Andrew 65789.87 5
Green Sheila 75892.56 6
Sethi Amit 74900.50 6.1
Each input line consists of an employee’s last name, first name, current salary,
and percent pay increase. For example, in the first input line, the last name of
the employee is Miller , the first name is Andrew , the current salary is
65789.87 , and the pay increase is 5% . Write a program that reads data from
the specified file and stores the output in the file Ch3_Ex7Output.dat .
For each employee, the data must be output in the following form:
firstName lastName updatedSalary . Format the output of decimal
numbers to two decimal places.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    // First employee (employee A) variable declaration
    string lastnameA, firstnameA;
    double currentSalaryA, percentPayIncreaseA, updatedSalaryA;

    // Second employee (employee B) variable declaration
    string lastnameB, firstnameB;
    double currentSalaryB, percentPayIncreaseB, updatedSalaryB;

    // Third employee (employee C) variable declaration
    string lastnameC, firstnameC;
    double currentSalaryC, percentPayIncreaseC, updatedSalaryC;

    ifstream inFile;                   // Declare input variable for file
    ofstream outFile;                  // Declare output variable for file
    inFile.open("Ch3_Ex7Data.txt");    // open input file
    outFile.open("Ch3_Ex7Output.dat"); // create and or open output file
    outFile << setprecision(2) << showpoint << fixed;

    // Employee processing for A B and C
    inFile >> lastnameA >> firstnameA >> currentSalaryA >>
        percentPayIncreaseA;

    inFile >> lastnameB >> firstnameB >> currentSalaryB >>
        percentPayIncreaseB;

    inFile >> lastnameC >> firstnameC >> currentSalaryC >>
        percentPayIncreaseC;

    // calculating updated salaries for employees A B and C
    updatedSalaryA = currentSalaryA + (currentSalaryA * percentPayIncreaseA / 100);
    updatedSalaryB = currentSalaryB + (currentSalaryB * percentPayIncreaseB / 100);
    updatedSalaryC = currentSalaryC + (currentSalaryC * percentPayIncreaseC / 100);

    outFile << lastnameA << " " << firstnameA << " " << updatedSalaryA << endl;
    outFile << lastnameB << " " << firstnameB << " " << updatedSalaryB << endl;
    outFile << lastnameC << " " << firstnameC << " " << updatedSalaryC << endl;

    // close input and output file
    inFile.close();
    outFile.close();
    return 0;
}