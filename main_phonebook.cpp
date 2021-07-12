// application file

#include "myphonebook.h"
using namespace std;

const int MAX_ENTRIES = 100;

int main() 
{
	
	string tempname, name;
	MyPhoneBook *myphbk;
	myphbk = new MyPhoneBook[MAX_ENTRIES];  // call to default constructor
	MyPhoneBook MyMobile;
	short int rowcount = 0, i = 0;
		
	// read existing entries from the file
	ifstream fin;
	ofstream fout;
	fin.open("myphonebook.txt", ios::in);
	if(fin.fail())
	    perror("Error opening file for reading\n");
	
	i=0;
	while(fin >> myphbk[rowcount]) // call to overloaded operator >>
	{    
		rowcount++;
		if(fin.eof())
			break;
	}
	fin.close();
	
	fout.open("myphonebook.txt", ios::out); // ordering file way needed for program operation (new line need at end of file) incase not already like this
		for(i=0; i < rowcount; i++)
	{
		fout << myphbk[i];
	}
	fout.close();
 	   
	cout << "Welcome to the phonebook\n";
	system("pause");
	system("cls");
	while(1){	//infinite loop so menu can be reused
	
		switch (menu())
		{
			case 1: //
				cout << "please enter the name of the persons number you would like to find\n";
				cin >> name;
				system("cls");
				for(i=0; i < rowcount; i++)
				{
					if(makeuppercase(name) == makeuppercase(myphbk[i].getname()))
					cout << "The number of " << myphbk[i].getname() << " is "<< myphbk[i].getarea() << " " << myphbk[i].getnumber() << endl;
					else if (makeuppercase(name) != makeuppercase(myphbk[i].getname()) && i == rowcount-1)
						cout << name << " could not be found\n";
				}
				
				system("pause");
				system("cls");
				break;
			case 2:	//add
				myphbk->add(rowcount, myphbk);
				break;
			case 3: //remove
				myphbk[i].display(rowcount, MAX_ENTRIES);
				
				myphbk->remove(rowcount, myphbk);
				break;
			case 4: //display
				system("cls");
				myphbk[i].display(rowcount, MAX_ENTRIES);
				system("pause");
				system("cls");
				break;
			case 5: //end
				return 0;
				break;
			default:
				cout << "option not found\n";
		}
	}
	return 0;
}
