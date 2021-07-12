// interface file
#ifndef MYPHONEBOOK_H
#define MYPHONEBOOK_H
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

class MyPhoneBook
{
public:
 MyPhoneBook(int,int, string, string, string, string);
 MyPhoneBook();
 ~MyPhoneBook();

 string getname()	{return *name;};
 string getnumber()	{return *number;};
 string getarea()	{return *areacode;};
 void add(short int&,MyPhoneBook []); 
 void remove(short int&,MyPhoneBook []); 
 void display(short int&,const int);
 
 friend bool operator == (const MyPhoneBook&, const MyPhoneBook&);
 friend istream& operator >> (istream&, MyPhoneBook&);
 friend ostream& operator << (ostream&, const MyPhoneBook&);
 
private:
 int *recordid; 
 int *status; // -1 is no longer at this number, 0 is blocked, 1 is not blocked, 2 is free
 string *name, *areacode, *number, *group;
};

int menu();
string	makeuppercase(const string&);


#endif
