#include <stdio.h>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

class ParkedCar
{
	string carMake;
	string carModel;
	string carColor;
	string licenseNumber;
	int minutesParked;
public:
	ParkedCar(string make, string model, string color, string num, int minutes)
	{
		carMake = make;
		carModel = model;
		carColor = color;
		licenseNumber = num;
		minutesParked = minutes;
		cout << "Creating car that has been parked for " << minutesParked << "." << endl;
	}
	string getCarMake(){return carMake;}
	string getCarModel(){return carModel;}
	string getCarColor(){return carColor;}
	string getLicenseNumber(){return licenseNumber;}
	int getMinutesParked(){return minutesParked;}
};

class ParkingMeter
{
	int minutesPayed;
public:
	ParkingMeter(int minutes)
	{
		minutesPayed = minutes;
		cout << "Creating parking meter that has been payed for " << minutesPayed << " minutes." << endl;
	}
	int getMinutesPayed(){return minutesPayed;}
};
class ParkingTicket
{

public:
	ParkingTicket(ParkedCar pc, string officerName, int badgeNumber)
	{
		cout << "Generating ticket for car..." << endl;
		cout << "Ticketed Car Info: " << pc.getCarMake() << ", " << pc.getCarModel() << ", " << pc.getCarColor() << ", " << pc.getLicenseNumber() << "." << endl;
		cout << "Officer Name and Badge Number: " << officerName << " " << badgeNumber << endl;
		int fine = reportFine(pc);
		cout << "Ticket fine: $" << fine << "." << endl;
	}
	int reportFine(ParkedCar pc)
	{
		int minutes = pc.getMinutesParked();
		int fine = 0;
		if(minutes > 0 && minutes < 60)
		{
			fine += 25;
			return fine;
		}
		if(minutes >= 60)
		{
			fine += 25;
			minutes -= 60;
		}
		while(minutes > 0)
		{
			fine += 10;
			minutes -= 60;
		}
		return fine;
	}
};
class PoliceOfficer
{
	string officerName;
	int badgeNumber;
public:
	PoliceOfficer(string name, int badge)
	{
		officerName = name;
		badgeNumber = badge;
		cout << "Creating police officer by the name of " << officerName << "with badge number " << badgeNumber << "." << endl;
	}
	void determineExpire(ParkedCar pc, ParkingMeter pm)
	{
		bool expire;
		if(pc.getMinutesParked() > pm.getMinutesPayed())
		{
			expire = true;
		}
		if(expire == true)
		{
			ParkingTicket pt(pc, officerName, badgeNumber);
		}
		else
			return;
	}

};
int main()
{
	//create all of the objects to simulate
	ParkedCar pc("Volkswagen", "Rabbit", "White", "8DKW291", 30);
	ParkingMeter pm(20);
	PoliceOfficer po("John", 1039288);

	//check if ticket should be issued
	po.determineExpire(pc, pm);
}
