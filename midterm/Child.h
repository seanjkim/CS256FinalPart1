#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <vector>
#include "Human.h"
#include "Parent.h"
using namespace std;

#ifndef CHILD_H_
#define CHILD_H_



class Child : public Human
{
	Parent mom;
	Parent dad;
	string work;
	Child()
		{
			mom = 0;
			dad = 0;
			workk = "";
		}

public:
	Child(Parent m, Parent d)
		{
			mom = m;
			dad = d;
		}
	void work(string w);
};

#endif /* CHILD_H_ */
