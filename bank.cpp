#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
using namespace std;

class SavingsAccount;
class CheckingAccount;



class BankAccount
{
protected:
	int numOfDeposits;
	int numOfWithdrawals;
	double annualInterestRate;
	double monthlyCharge;
	double balance;

public:
	BankAccount(double b, double a)
	{
		balance = b;
		annualInterestRate = a;
		numOfDeposits = 0;
		numOfWithdrawals = 0;
		monthlyCharge = 0;
	}
	double getBalance(){return balance;}
	void decrementBalance(double b){balance -= b;}
	double getMonthlyCharge(){return monthlyCharge;}
	void setMonthlyCharge(double m){monthlyCharge = m;}
	void addMonthlyCharge(double m){monthlyCharge += m;}
	double getNumOfDeposits(){return numOfDeposits;}
	double getNumOfWithdrawals(){return numOfWithdrawals;}
	void setNumOfDeposits(int n){numOfDeposits = n;}
	void setNumOfWithdrawals(int n){numOfWithdrawals = n;}
	void deposit(double b)
	{
		balance += b;
		numOfDeposits++;
	}
	void withdraw(double b)
	{
		balance -= b;
		numOfWithdrawals++;
	}
	void calcInt()
	{
		double monthlyInterestRate = (annualInterestRate / 12);
		double monthlyInterest = balance * monthlyInterestRate;
		balance = balance + monthlyInterest;
	}
	virtual void monthlyProc()
	{
		balance -= monthlyCharge;
		calcInt();
		numOfWithdrawals = 0;
		numOfDeposits = 0;
		monthlyCharge = 0;
	}
};
class SavingsAccount : public BankAccount
{
bool status;
public:
SavingsAccount(double b, double a) : BankAccount(b, a)
{
	balance = b;
	annualInterestRate = a;
	if(getBalance() > 25)
		status = true;
	else
		status = false;
}
void setStatus(bool s){status = s;}
void withdraw(double b)
{
	if(status == true)
	{
		BankAccount::withdraw(b);
	}
	else
		cout << "Account is inactive. No withdrawal is allowed." << endl;
}
void deposit(double b)
{
	if(status == false && (getBalance() + b > 25))
	{
		status = true;
		BankAccount::deposit(b);
		return;
	}
	if(status == true)
	{
		BankAccount::deposit(b);
		return;
	}
	else
		cout << "Account is inactive. No deposit is allowed." << endl;
}
void monthlyProc()
{
	if(getNumOfWithdrawals() > 4)
	{
		setMonthlyCharge(1);
	}
	BankAccount::monthlyProc();
	if(getBalance() < 25)
	{
		status = false;
	}
}
};
class CheckingAccount : public BankAccount
{
public:
	CheckingAccount(double b, double a) : BankAccount(b, a)
	{
		balance = b;
		annualInterestRate = a;
	}
	void withdraw(double b)
	{
		if((getBalance() - b) < 0)
		{
			cout << "Invalid withdrawal. $15 service charged to your account." << endl;
			decrementBalance(15);
		}
		else
			BankAccount::withdraw(b);
	}
	void monthlyProc()
	{
		addMonthlyCharge(5 + (getNumOfWithdrawals() * 0.10));
		BankAccount::monthlyProc();
	}
};

int main()
{
	int numOfDeposits;
	int numOfWithdrawals;

	cout << "Hello! Let's first make a checking account before making a savings account." << endl;

	cout << "Please input the initial number of deposits for the checking account." << endl;
	cin >> numOfDeposits;

	cout << "Now please enter the initial number of withdrawals for the checking account." << endl;
	cin >> numOfWithdrawals;

	CheckingAccount ca(100, .03);
	ca.setNumOfDeposits(numOfDeposits);
	ca.setNumOfWithdrawals(numOfWithdrawals);

	cout << "Checking account created. Now creating savings account..." << endl;

	cout << "Please input the initial number of deposits for the savings account." << endl;
	cin >> numOfDeposits;

	cout << "Now please enter the initial number of withdrawals for the savings account." << endl;
	cin >> numOfWithdrawals;

	SavingsAccount sa(300, .05);
	sa.setNumOfDeposits(numOfDeposits);
	sa.setNumOfWithdrawals(numOfWithdrawals);
	cout << "Savings account created." << endl;

	bool done = false;
	int decision;
	while(done == false)
	{
		cout << "Input 1 to see monthly statistics for your checking account or input 2 to see monthly statistics for your savings account." << endl;
		cout << "Input 3 to simulate a month going by. Input any other digit to exit out of the program." << endl;
		cin >> decision;
		if(decision == 1)
		{
			cout << "Checking account starting balance: " << ca.getBalance() << endl;
			cout << "Total amount of deposits: " << ca.getNumOfDeposits() << endl;
			cout << "Total amount of withdrawals: " << ca.getNumOfWithdrawals() << endl;
			cout << "Current service charges: " << ca.getMonthlyCharge() << endl;

		}
		else if(decision == 2)
		{
			cout << "Savings account starting balance: " << sa.getBalance() << endl;
			cout << "Total amount of deposits: " << sa.getNumOfDeposits() << endl;
			cout << "Total amount of withdrawals: " << sa.getNumOfWithdrawals() << endl;
			cout << "Current service charges: " << sa.getMonthlyCharge() << endl;
		}
		else if(decision == 3)
		{
			cout << "One month went by.." << endl;
			ca.monthlyProc();
			sa.monthlyProc();
		}
		else
		{
			done = true;
		}
	}
	return 0;
}
