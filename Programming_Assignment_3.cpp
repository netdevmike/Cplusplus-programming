/*
Chapter 7 - Exercise 5
 
Write a program that can be used to calculate the federal tax. The tax is calculated as follows: For single people, the standard exemption is $4,000; for married people, the standard exemption is $7,000. A person can also put up to 6% of his or her gross income in a pension plan. The tax rates are as follows: If the taxable income is:
    - Between $0 and $15,000, the tax rate is 15%.
    - Between $15,001 and $40,000, the tax is $2,250 plus 25% of the taxable
    - income over $15,000.
Over $40,000, the tax is $8,460 plus 35% of the taxable income over
$40,000.
Prompt the user to enter the following information:
    - Marital status
    - If the marital status is “married,” ask for the number of children under
    - the age of 14
Gross salary (If the marital status is “married” and both spouses have
    - income, enter the combined salary.)
Percentage of gross income contributed to a pension fund
Your program must consist of at least the following functions:
    a. Function getData: This function asks the user to enter the relevant data.
    b. Function taxAmount: This function computes and returns the tax owed.
To calculate the taxable income, subtract the sum of the standard exemption, the amount contributed to a pension plan, and the personal exemption, which is $1,500 per person. (Note that if a married couple has two children under the age of 14, then the personal exemption is $1,500 ∗ 4 5 $6,000.)
 */

//Declare Header files
#include <iostream>
#include <string>
using namespace std;

//function prototypes
void getData(char &marital_status, int &num_Persons, double &gross_Salary, double &pension);
double taxAmount(char marital_status, int num_Persons, double gross_Salary, double pension);
double getFederal_Tax(double taxable_Income);

//main function
int main()
{
    char marital_status = ' ';
    int num_Persons = 0;
    double gross_Salary = 0, pension_contri = 0;
    double federal_tax = 0, taxable_Income = 0;

    cout << "Program to compute the federal tax: " << endl
         << endl;
    cout << "Please answer the questions below" << endl
         << endl;

    // function calls
    // call getData() by passing values as reference
    getData(marital_status, num_Persons, gross_Salary, pension_contri);
    // call taxAmount() function to calculate the taxable income
    taxable_Income = taxAmount(marital_status, num_Persons, gross_Salary, pension_contri);
    // call getFederal_Tax() function to calculate the federal tax depending

    // on taxable income
    federal_tax = getFederal_Tax(taxable_Income);

    //Print details
    cout << "\nFederal Tax details of a person: " << endl;
    cout << "Marital Status: " << marital_status << endl;
    cout << "Number of Persons in the family: " << num_Persons << endl;
    cout << "Income earned: " << gross_Salary << endl;
    cout << "Pension Plan contribution: " << pension_contri << endl;
    cout << "\nTaxable Income: " << taxable_Income << endl;
    cout << "\nFederal Tax payable is: " << federal_tax << endl;

    system("pause");

    return 0;
}

//The getData() function asks the user to enter the relevant information
void getData(char &marital_status, int &num_Persons, double &gross_Salary, double &pension)
{
    char reply;
    int num_of_children = 0;

    //prompt for marital status
    cout << "What is your your Marital Status: "
         << "\n[M]arried or [S]ingle: ";
    cin >> marital_status;

    //if married prompt the following statements
    if (marital_status == 'm' || marital_status == 'M')
    {
        //ask for number of childern under the age of 14
        cout << "\nEnter the number of children under age 14: ";
        cin >> num_of_children;
        num_Persons = 2 + num_of_children;

        //Ask if both earn an income
        cout << "\nDo both spouses earn income? \n"
             << "Enter [Y]es or [N]o: ";
        cin >> reply;
        cout << endl;

        //if both earn a salary than prompt for combined income
        if (reply == 'y' || reply == 'Y')
        {
            cout << "Please enter your combined salary: ";
            cin >> gross_Salary;
            cout << endl;
        }
        //prompt for single income
        else
        {
            cout << "Please enter your salary: ";
            cin >> gross_Salary;
            cout << endl;
        }
    }
    //if they are single prompt for salary
    else
    {
        cout << "\nPlease enter your salary: ";
        cin >> gross_Salary;
        cout << endl;
        num_Persons = 1;
    }

    //prompt for pension plan (integer values)
    cout << "Please enter your Pension Plan contribution(limit upto 6%): ";
    cin >> pension;

    //limit is upto 6 only
    while (pension > 6.00)
    {
        cout << "The limit is upto 6% only." << endl;
        cout << "Please enter your Pension Plan contribution(limit upto 6%): ";
        cin >> pension;
    }

    //calculate the pension amount over gross income
    pension = pension / 100 * gross_Salary;
    cout << endl;
}

//taxAmount() function computes and returns the tax owed.
double taxAmount(char marital_status, int num_Persons, double gross_Salary, double pension)
{
    //declare the required variables
    double stand_exemption = 0;
    double taxableIncome;

    //if the married status is m or M then std. exemption is 7000
    if (marital_status == 'm' || marital_status == 'M')
        stand_exemption = 7000;
    //if the married status is not m and M then std. exemption is 4000
    else
        stand_exemption = 4000;

    // subtract the sum of standard exemption, the amount contributed to a pension plan, and the personal exemption from the gross salary
    taxableIncome = gross_Salary - ((1500.00 * num_Persons) + pension + stand_exemption);

    // return the taxable income value
    return (taxableIncome);
}

// getFederal_Tax() calculates the federal tax value depending on the
// taxable income
double getFederal_Tax(double taxable_Income)
{
    //conditions and repective return values
    if (taxable_Income >= 0 && taxable_Income <= 15000)
        return taxable_Income * 0.15;
    else if (taxable_Income >= 15001 && taxable_Income <= 40000)
        return 2250.00 + taxable_Income * 0.25;
    else
        return 8460.00 + taxable_Income * 0.35;
}