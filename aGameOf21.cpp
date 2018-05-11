#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Die
{
private:
	int sides;
	int value = 0;
public:
	Die(int = 6);
	void roll();
	int getSides();
	int getValue();

};
Die::Die(int numSides)
{
	unsigned seed = time(0);
	srand(seed);
	sides = numSides;

}
void Die::roll()
{
	const int MIN_VALUE = 1;
	value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
}
int Die::getSides()
{
	return sides;
}
int Die::getValue()
{
	return value;
}
int main()
{
	int computerTotal;
	int yourTotal;
	int decision;
	bool done = true;

	Die die(6);
	die.roll();
	computerTotal += die.getValue();
	die.roll();
	computerTotal += die.getValue();
	cout << "Enter 1 to begin the game and roll two six-sided die." << endl;
	cin >> decision;
	if(decision == 1)
	{
		die.roll();
		yourTotal += die.getValue();
		die.roll();
		yourTotal += die.getValue();
		cout << "You rolled " << yourTotal << "." << endl;
	}
	else
	{
		cout<< "Goodbye!" << endl;
	}
	while(done == true)
	{
		cout << "Enter 1 if you would like to roll again or enter 2 if you would like to stop." << endl;
		cin >> decision;
		if(decision == 1)
		{
			die.roll();
			int tempInt = die.getValue();
			yourTotal += die.getValue();
			cout << "You rolled " << tempInt << " making your total " << yourTotal << endl;
		}
		if(decision == 2)
		{
			done = false;
			cout << "Your ending total is.. " << yourTotal << "!" << endl;
			cout << "The computer's ending total is.. " << computerTotal << "!" << endl;
			if(yourTotal > computerTotal)
			{
				cout << "You win!" << endl;
				return 0;
			}
			if(yourTotal < computerTotal)
			{
				cout << "You lose!" << endl;
				return 0;
			}
			if( yourTotal == computerTotal)
			{
				cout << "You tied!" << endl;
				return 0;
			}
		}
		if(yourTotal > 21)
		{
			done = false;
			cout<< "You rolled a total over 21! You lose!" << endl;
			return 0;
		}
	}
}
