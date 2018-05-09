#include <stdio.h>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

class PersonData
{
	string firstName;
	string lastName;
	string address;
	string city;
	string state;
	string zip;
	string phone;
public:
	string getFirstName(){return firstName;}
	void setFirstName(string f){firstName = f;}
	string getLastName(){return lastName;}
	void setLastName(string l){lastName = l;}
	string getAddress(){return address;}
	void setAddress(string a){address = a;}
	string getCity(){return city;}
	void setCity(string c){city = c;}
	string getState(){return state;}
	void setState(string s){state = s;}
	string getZip(){return zip;}
	void setZip(string z){zip = z;}
	string getPhone(){return phone;}
	void setPhone(string p){phone = p;}
};

class CustomerData : public PersonData
{
	int customerNumber;
	bool mailingList;
public:
	int getCustomerNumber(){return customerNumber;}
	void setCustomerNumber(int i){customerNumber = i;}
	bool getMailingList(){return mailingList;}
	void setMailingList(bool b){mailingList = b;}

};

class PreferredCustomer : public CustomerData
{
	double purchasesAmount;
	double discountLevel = 0;
public:
	double getPurchasesAmount(){return purchasesAmount;}
	void purchase()
	{
		double tempPrice;
		cout << "Input a price to simulate buying an item. ex. 125.99" << endl;
		cin >> tempPrice;
		while(tempPrice < 0)
		{
			cout << "Please input a positive price." << endl;
			cin >> tempPrice;
		}
		tempPrice = tempPrice - (tempPrice * discountLevel);
		cout << "With your discount levels the new price of the item is..." << tempPrice << "." << endl;
		purchasesAmount += tempPrice;
	}
	void checkLevel()
	{
		if(purchasesAmount >= 500 && purchasesAmount < 1000)
		{
			discountLevel = .05;
		}
		if(purchasesAmount >= 1000 && purchasesAmount < 1500)
		{
			discountLevel = .06;
		}
		if(purchasesAmount >= 1500 && purchasesAmount < 2000)
		{
			discountLevel = .07;
		}
		if(purchasesAmount >= 2000)
		{
			discountLevel = .1;
		}
	}
};
int main()
{
	PreferredCustomer pc;
	int decision = 0;
	bool done = true;

	pc.setFirstName("John");
	pc.setLastName("Smith");
	pc.setAddress("1234 Computer Street");
	pc.setCity("Vegas Baby");
	pc.setState("Antarctica");
	pc.setZip("91191");
	pc.setPhone("301-482-2269");
	pc.setCustomerNumber(124820);

	cout << "Welcome to the store!" << endl;
	cout << "Enter 1 if you would like to be on the mailing list, or any other digit to not be." << endl;
	cin >> decision;
	if(decision == 1)
	{
		cout << "Setting your mailing list..." << endl;
		cout << "Name: " << pc.getFirstName() << pc.getLastName() << endl;
		cout << "Address: " << pc.getAddress() << ", " << pc.getCity() << ", " << pc.getState() << ", " << pc.getZip() << endl;
		cout << "Phone Number: " << pc.getPhone() << endl;
		cout << "Customer Number: " << pc.getCustomerNumber() << endl;
		pc.setMailingList(true);
	}

	while(done == true)
	{
		cout << "Input 1 if you would like to purchase an item or input any other digit to exit." << endl;
		cin >> decision;
		if(decision == 1)
		{
			pc.purchase();
			cout << "You have now spent a total of " << pc.getPurchasesAmount() << endl;
			pc.checkLevel();
		}
		else
			return 0;
	}
	return 0;
}
