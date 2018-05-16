#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <vector>
#include "Human.h"
#include "Child.h"
using namespace std;

#ifndef PARENT_H_
#define PARENT_H_

class Parent : public Human
{
	vector<Child> children;
	string work;
public:
	void setChildren(Child c);
	vector<Child> getChildren();
	void work(string w);
	void changeChildName(Child c, string n);
};


#endif /* PARENT_H_ */
