/* 
#4 on pages 812-813 of C++ Programming. 

4.Amanda and Tyler opened a business that specializes in shipping liquids, such as milk, juice, and water, in cylindrical containers.
The shipping charges depend on the amount of the liquid in the container. (For simplicity, you may assume that the container is filled to the top.) 
They also provide the option to paint the outside of the container for a reasonable amount.

Write a program that does the following:
a. Prompts the user to input the dimensions (in feet) of the container (radius of the base and the height).
b. Prompts the user to input the shipping cost per liter.
c. Prompts the user to input the paint cost per square foot. (Assume that the entire container including the top and bottom needs to be painted.)
d. Separately outputs the shipping cost and the cost of painting. Your program must use the class cylinderType (designed in Programming Exercise 3) to store the radius of the base and the height of the container.
(Note that 1 cubic feet 5 28.32 liters or 1 liter 5 0.353146667 cubic feet.)
*/

// header files
#include <iostream>
#include <iomanip>
using namespace std;

// cylinderType class which was designed in programming exercise 3
class cylinderType
{
public:
    cylinderType();
    cylinderType(double, double);
    void setRadius(double);
    void setHeight(double);
    double getRadius() const;
    double getHeight() const;
    double getArea() const;
    double getVolume() const;
   
private:
    double radius;
    double height;
};

cylinderType::cylinderType()
{
    radius = 0;
    height = 0;
}

cylinderType::cylinderType(double newRadius, double newHeight)
{
    radius = newRadius;
    height = newHeight;
}

void cylinderType::setRadius(double newRadius)
{
    radius = newRadius;
}

void cylinderType::setHeight(double newHeight)
{
    height = newHeight;
}

double cylinderType::getRadius() const
{
    return radius;
}

double cylinderType::getHeight() const
{
    return height;
}

double cylinderType::getArea() const
{
    return ((2 * 3.1416 * radius * radius) + (2 * 3.1416 * radius * height));
}

double cylinderType::getVolume() const
{
    return (3.1416 * radius * radius * height);
}

double getShippingCost(double, double);
double getPaintingCost(double, double);

// main function
int main()
{
    double radiusInFeet;
    double heightInFeet;
    double shippingCostPerLiter;
    double paintCostPerSquareFoot;
    double volume;
    double area;
    double shippingCost;
    double paintingCost;

   // prompt user to input dimensions, shipping cose, and pain cost
    cout << "Enter the dimensions (in feet) of the container (radius of the base and the height): ";
    cin >> radiusInFeet >> heightInFeet;

    cylinderType ct(radiusInFeet, heightInFeet);

    cout << "Enter the shipping cost per liter: ";
    cin >> shippingCostPerLiter;

    cout << "Enter the paint cost per square foot: ";
    cin >> paintCostPerSquareFoot;
   
    volume = ct.getVolume();
    area = ct.getArea();
    shippingCost = getShippingCost(volume, shippingCostPerLiter);
    paintingCost = getPaintingCost(area, paintCostPerSquareFoot);

   // output results to user
    cout << endl << fixed << showpoint << setprecision(2);
    cout << "The volume of the cylinder: " << volume << " Cubic Feet" << endl;
    cout << "The surface area of the cylinder: " << area << " Square Feet" << endl;
    cout << "The total shipping cost: $" << shippingCost << endl;
    cout << "The total cost per painting: $" << paintingCost << endl;

    system("pause");
    return 0;
}

// getShippingCost function
double getShippingCost(double volume, double shippingCostPerLiter)
{
    return volume * 28.32 * shippingCostPerLiter;
}

// getPaintingCose function
double getPaintingCost(double area, double paintCostPerSquareFoot)
{
    return area * paintCostPerSquareFoot;
}