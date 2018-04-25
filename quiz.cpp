#include <stdio.h>
#include <iostream>

using namespace std;

class Circle
{
	double radius;
	double pi = 3.14156;
public:
	Circle(double r = 0)
	{
		radius = r;
	}
	void setRadius(double r)
	{
		radius = r;
	}
	double getRadius()
	{
		return radius;
	}
	double getArea()
	{
		double area = pi * radius * radius;
		return area;
	}
	double getDiameter()
	{
		double diameter = radius * 2;
		return diameter;
	}
	double getCircumference()
	{
		double circumference = 2 * pi * radius;
		return circumference;
	}
};
int main()
{
	double rad;
	cout << "What is the circle's radius?" << endl;
	cin >> rad;
	Circle circle(rad);
	cout << "The circle's area is: " << circle.getArea() << endl;
	cout << "The circle's diameter is: " << circle.getDiameter() << endl;
	cout << "The circle's circumference is: " << circle.getCircumference() << endl;
}
