#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <vector>
#include "Child.h"
#include "Human.h"
#include "Parent.h"
using namespace std;

void Human::setName(string n){name = n;}
void Human::setAge(int a){age = a;}
void Human::setSex(char s){sex = s;}


string Human::getName(){return name;}
int Human::getAge(){return age;}
char Human::getSex(){return sex;}

void Child::work(string w){work = w;}

void Parent::setChildren(Child c){children.push_back(c);}
vector<Child> Parent::getChildren(){return children;}
void Parent::work(string w){work = w;}
void Parent::changeChildName(Child c, string n)
{
	c.setName()
}
