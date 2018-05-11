#include <stdio.h>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

class Ship
{
protected:
	string shipName;
	string yearMade;
public:
	Ship(string name, string year)
	{
		shipName = name;
		yearMade = year;
	}
	string getShipName(){ return shipName;}
	void setShipName(string name){shipName = name;}

	string getYearMade(){return yearMade;}
	void setYearMade(string year){yearMade = year;}

	virtual void print()
	{
		cout << "Ship's name: " << shipName << endl;
		cout << "Year made: " << yearMade << endl;
	}
};
class CruiseShip : public Ship
{
	int maxPassengers;
public:
	CruiseShip(int p, string n, string y);
	int getMaxPassengers(){return maxPassengers;}
	void setMaxPassengers(int passengers){maxPassengers = passengers;}
	void print()
	{
		cout << "Ship's name: " << getShipName() << endl;
		cout << "Maximum number of passengers: " << maxPassengers << endl;
	}
};
CruiseShip::CruiseShip(int passengers, string name, string year) : Ship(name, year)
	{
		maxPassengers = passengers;
		shipName = name;
		yearMade = year;
	}
class CargoShip : public Ship
{
	int cargoCapacity;
public:
	CargoShip(int c, string n, string y);
	int getCargoCapacity(){return cargoCapacity;}
	void setCargoCapacity(int capacity){cargoCapacity = capacity;}
	void print()
	{
		cout << "Ship's name: " << getShipName() << endl;
		cout << "Cargo Capacity in tons: " << cargoCapacity << endl;
	}
};
CargoShip::CargoShip(int capacity, string name, string year) : Ship(name, year)
	{
		cargoCapacity = capacity;
		shipName = name;
		yearMade = year;
	}
int main()
{
	Ship* array[3] = {new Ship("Baby", "1969"), new CruiseShip(500, "Kevin", "1958"), new CargoShip(5000, "Mom", "2011")};

	for(int i = 0; i < 3; i++)
	{
		array[i]->print();
	}
	return 0;
}
