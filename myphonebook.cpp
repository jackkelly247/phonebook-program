// implementation file
#include "myphonebook.h"

using namespace std;
short int RID = 1;

MyPhoneBook::MyPhoneBook(int RID, int stat, string nm, string ac, string no, string grp)
{
	recordid = new int;
	*recordid = RID;
	status = new int;
	*status = stat;
	name = new string;
	*name = nm;
	areacode = new string;
	*areacode = ac;
	number = new string;
	*number = no;
	group = new string;
	*group = grp;
}

MyPhoneBook::MyPhoneBook()
{
	recordid = new int;
	*recordid = RID;
	status = new int;
	*status = 2;
	name = new string;
	*name = "undefined";
	areacode = new string;
	*areacode = "000";
	number = new string;
	*number = "0000000";
	group = new string;
	*group = "undefined";
	RID++;
}

MyPhoneBook::~MyPhoneBook()
{
	delete recordid;
	delete status;
	delete name;
	delete areacode;
	delete number;
	delete group;
}



void MyPhoneBook::add(short int &rc,MyPhoneBook ph[])
{ 
	
	short int i, status,rid;
 	string name, areacode, number, group;
	ofstream fout;
	cout << "please enter the folliwng details about the contact you would like to add\n";
	system("pause");
	system("cls");
	
	cout << "please enter the name of the contact\n";
	cin >> name;
	system("pause");
	system("cls");
	
	cout << "please enter the areacode of the contact\n";
	cin >> areacode;
	while(areacode.length() > 3 )// max area code length gloabally
	{
		cout << "area code entered is too long max length of area codes is 3 gloabally, please try again\n"; 
		cin >> areacode;
	}
	system("pause");
	system("cls");
	
	cout << "please enter the number of the contact\n";
	cin >> number;
	while(number.length() > 15 )
	{
		cout << "number entered is too long max length of phone number accepted is 15, please try again\n"; // 15 is sposedely the longest phone number globally
		cin >> number;
	}
	system("pause");
	system("cls");
	
	cout << "please enter the conact type e.g friend family etc.\n";
	cin >> group;
	system("pause");
	system("cls");
	
	rid = rc+1;
	status = 1; // assuming people are not adding blocked numbers or peoples old numbers
	MyPhoneBook temp(rid, status, name, areacode, number, group);
	for(i=0;i < rc; i++)
	{
		if (temp.getnumber() == ph[i].getnumber()) //if (temp == ph[i]) was originally attempted to use overloaded operator but did not work
		{
			cout <<"This person has already been added to the phone book returning to menu...\n";
			system("pause");
			system("cls");
			return;
		}
	}
	
		ph[rc+1] = temp;
		fout.open("myphonebook.txt", ios::app);
		if(fout.fail())
		{
			perror("error opening file for appending");			// appending new contact to file
		}
		
		fout  << ph[rc+1] << endl; // adding number to phone book using overloaded operator
		
		fout.close();		// closing file
		
		rc++;
	return;
}



void MyPhoneBook::remove(short int &rc, MyPhoneBook ph[])
{
	MyPhoneBook temp;
	short int i,pos;
	ofstream fout;
	
	do{
	
		cout << "enter the row number of the person you want to remove from the phone book (number furthest left)\n";
		cin >> pos;
		while(cin.fail())
			{
				cin.clear();
		  		cin.ignore(80,'\n');		// testing for a non numeric entry
		  		cout << "invalid option please enter a number\n";
				cin >> pos;
			}
		if(pos-1 > rc || pos-1 < 0)
			cout << "cout invalid option entered please try again\n";
		}while(pos-1 > rc || pos-1 < 0);
	
	for(i=pos-1; i < rc; i++)
	{
		ph[i] = ph[i+1];
		*ph[i].recordid = *ph[i].recordid-1;
	}
		
	pos--;

	ph[rc] = temp;
	*ph[rc].recordid = rc;
	
	fout.open("myphonebook.txt",ios::out);
	if(fout.fail())
	    perror("Error opening file for Writing\n");
	    
	rc--;
	for(i=0; i < rc; i++)
	{
		fout << ph[i];
	}
	

	return;
} 

void MyPhoneBook::display(short int &rc, const int MAX_ENTRIES)
{
	ifstream fin;
	
	fin.open("myphonebook.txt", ios::in);
	if(fin.fail())
		perror ("file could not be opened");			// output file contents
	if(fin.is_open())
		cout << fin.rdbuf();
	cout << "you also have " << MAX_ENTRIES-rc << " free spaces for new contacts\n";
	fin.close();
}

istream& operator >> (istream& in, MyPhoneBook& ph)
{
	in >> *ph.recordid >> *ph.status >> *ph.name >> *ph.areacode >> *ph.number >> *ph.group;
	return in;
}

ostream& operator << (ostream& out, const MyPhoneBook& ph)
{
	out << *ph.recordid << " " << *ph.status << " " << *ph.name << " " << *ph.areacode << " " << *ph.number << " " << *ph.group << endl;
	return out;
}

bool operator == (const MyPhoneBook& obj1, const MyPhoneBook& obj2)
{
	
	return (obj1.number == obj2.number);
}

int menu()
{
	int ch;
	do{
		
		cout << "please choose one of the options below:\n";
		cout << "if you would like to find someones phone number enter 1\n";
		cout << "if you would like to add someone to the phone book enter 2\n";
		cout << "if you would like to remove a contact from the phone book enter 3\n";
		cout << "if you would like to display all of your contacts enter 4\n";
		cout << "if you would like to end the program enter 5\n";
		cin >> ch;
		while(cin.fail())
				{
					cin.clear();
			  		cin.ignore(80,'\n');		// testing for a non numeric entry
			  		cout << "invalid option please enter a number\n";
					cin >> ch;
					
				}
				
		if(ch > 5 || ch < 0)
		{
			cout << "The option you entered is not from the list above please try again\n";
			system("pause");
			system("cls");	
		}
	}while(ch > 5 || ch < 1);
return ch;	
}

string	makeuppercase(const string& in)
{
	string	out;
	transform(in.begin(), in.end(), std::back_inserter(out), ::toupper);
	return out;
}

