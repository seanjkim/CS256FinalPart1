#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

#ifndef HUMAN_H_
#define HUMAN_H_

class Human
{
	string name;
	int age;
	char sex;
	Human()
		{
			name = "";
			age = 0;
			sex = 'm';
		}
protected:
Human(string n, int a, char s)
	{
		name = n;
		age = a;
		sex = s;
	}
public:
	//setters
	void setName(string n);
	void setAge(int a);
	void setSex(char s);

	//getters
	string getName();
	int getAge();
	char getSex();

	virtual void work(string w);
};



#endif /* HUMAN_H_ */
