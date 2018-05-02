#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class DayOfTheYear
{
	int month;
	int day;
	string sep = "September ";
	string oct = "October ";
	string nov = "November ";
	string dec = "December ";
	string jan = "January ";
	string feb = "February ";
	string mar = "March ";
	string apr = "April ";
	string may = "May ";
	string jun = "June ";
	string jul = "July ";
	string aug = "August ";

public:
	DayOfTheYear(int d)
	{
		day = d;
		month = 0;
	}
	DayOfTheYear(int m, int d)
	{
		month = m;
		day = d;
		while(month < 1 || month > 12)
		{
			cout << "Please input a valid month number." << endl;
			cin >> month;
		}
	}
	void print();
};
void DayOfTheYear::print()
{
	if(month != 0)
	{
		month -= 1;
		if(month == 0)
					{
						cout << jan << day << endl;
					}
					if(month == 1)
								{
									cout << feb << day << endl;
								}
					if(month == 2)
								{
									cout << mar << day << endl;
								}
					if(month == 3)
								{
									cout << apr << day << endl;
								}
					if(month == 4)
								{
									cout << may << day << endl;
								}
					if(month == 5)
								{
									cout << jun << day << endl;
								}
					if(month == 6)
								{
									cout << jul << day << endl;
								}
					if(month == 7)
								{
									cout << aug << day << endl;
								}
					if(month == 8)
								{
									cout << sep << day << endl;
								}
					if(month == 9)
								{
									cout << oct << day << endl;
								}
					if(month == 10)
								{
									cout << nov << day << endl;
								}
					if(month == 11)
								{
									cout << dec << day << endl;
								}
	}
	cout << "Day " << day << endl;
	int counter = 0;
			if(day > 31 && day > 0) //jan
			{
				day -= 31;
				counter++;
			}
			if(day > 28 && day > 0) //feb
			{
				day -= 28;
				counter++;
			}
			if(day > 31 && day > 0) //mar
			{
				day -= 31;
				counter++;
			}
			if(day > 30 && day > 0) //apr
			{
				day -= 30;
				counter++;
			}
			if(day > 31 && day > 0) //may
			{
				day -= 31;
				counter++;
			}
			if(day > 30 && day > 0) //jun
			{
				day -= 30;
				counter++;
			}
			if(day > 31 && day > 0) //jul
			{
				day -= 31;
				counter++;
			}
			if(day > 31 && day > 0) //aug
			{
				day -= 31;
				counter++;
			}
			if(day > 30 && day > 0) //sep
			{
				day -= 30;
				counter++;
			}
			if(day > 31 && day > 0) //oct
			{
				day -= 31;
				counter++;
			}
			if(day > 30 && day > 0) //nov
			{
				day -= 30;
				counter++;
			}
			if(day > 31 && day > 0) //dec
			{
				day -= 31;
				counter++;
			}
			if(counter == 0)
			{
				cout << jan << day << endl;
			}
			if(counter == 1)
						{
							cout << feb << day << endl;
						}
			if(counter == 2)
						{
							cout << mar << day << endl;
						}
			if(counter == 3)
						{
							cout << apr << day << endl;
						}
			if(counter == 4)
						{
							cout << may << day << endl;
						}
			if(counter == 5)
						{
							cout << jun << day << endl;
						}
			if(counter == 6)
						{
							cout << jul << day << endl;
						}
			if(counter == 7)
						{
							cout << aug << day << endl;
						}
			if(counter == 8)
						{
							cout << sep << day << endl;
						}
			if(counter == 9)
						{
							cout << oct << day << endl;
						}
			if(counter == 10)
						{
							cout << nov << day << endl;
						}
			if(counter == 11)
						{
							cout << dec << day << endl;
						}

}
int main()
{
	cout << "Please enter a number between 0 and 365." << endl;
	int day;
	int month;
	cin >> month;
	cin >> day;
	DayOfTheYear calculate(month, day);
	calculate.print();
	return 0;
}
