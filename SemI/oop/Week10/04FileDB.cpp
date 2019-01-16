/*
@author Ankit
 @date 29/10/2018
 @week 10
 @desc file i/o
Write a C++ program to create an item database and store the following information: 
i. Item name 
ii. Item code  
iii. Unit price 
iv. Quantity on hand 
Then implement the following: 
i. Add a new record 
ii. Modify the existing record 
iii. Delete a record. 
Use random access file concept. The item code should be generated automatically.
*/

#include <iostream>
#include <fstream>
using namespace std;

//ifstream - read only
//ofstream - write only
//ascii 30 - record separator

//note at the very top of the file, the very first character is '\n' so  that findRecord() can work correctly

const unsigned char recordSep = '\n';
const unsigned char unitSep = ' ';

void addRecord(bool isNew, int code)
{
	ofstream fl("04slfile.db", ios::app|ios::binary);
	//https://stackoverflow.com/questions/2390912/checking-for-an-empty-file-in-c
	//if(fl.peek() == fl.eof()) fl << '\n';
	char name[10] = { '\0' };
	cout << "Name : "; cin >> name;
	if(isNew)
	{
		cout << "Code : "; cin >> code;
	}
	int price, qty;
	cout << "Price : "; cin >> price;
	cout << "Quantity : "; cin >> qty;
	fl << name << unitSep << code << unitSep << price << unitSep << qty << recordSep;
	fl.close();
}

int findRecord(int id, bool* found, int* size)
{
	ifstream fl("04slfile.db", ios::binary);
	int currentId = 0; int location;
	fl.seekg(ios::beg);
	while(!*found && !fl.eof())
	{
		//skipping ahead of name
		while(fl.peek() != unitSep)
			fl.seekg(1, fl.cur);

		fl >> currentId;
		if(id == currentId)
		{
			*found = true;
			//moving to beginning of this record, just before the beginning of it's first character
			while( (fl.peek() != recordSep) || (fl.tellg() != fl.beg) )
				fl.seekg(-1, fl.cur);
			fl.seekg(1, fl.cur);
			location = fl.tellg();
			//
			char k[11]; fl.read(k, 11);
			fl.seekg(-11, fl.cur);
			//getting size
			while(fl.peek() != recordSep)
				fl.seekg(1, fl.cur);
			//also including the recordSep of this record
			fl.seekg(1, fl.cur);
			int endLoc = fl.tellg();
			*size = endLoc - location;
		}
		else
		{
			//to next record
			do
			{
				fl.seekg(1, fl.cur);
			}
			while(fl.peek() != recordSep && !fl.eof());
		}
	}
	fl.close();
	return location;
}

void deleteRecord(int code)
{
	bool found = false; int size = 0;
	int location = findRecord(code, &found, &size);
	fstream fl("04slfile.db", ios::ate|ios::binary|ios::out);
	fl.seekp(location, fl.beg);
	char k[size] = { '\0' };
	fl.write(k, size);
	fl.close();
	return;
}

void modifyRecord(int code)
{
	deleteRecord(code);
	addRecord(false, code);
	return;
}

int main(void)
{
	cout << "1. Add Records\n";
	cout << "2. Modify\n";
	cout << "3. Delete\n";
    int choice, code;
    while(true)
    {
    cout << "\nChoice : "; cin >> choice;
    switch(choice)
    {
    	case 1:
    		addRecord(true, 0);
    		break;

    	case 2:
    		cout << "Code : "; cin >> code;
   			modifyRecord(code);
   			break;

   		case 3:
   			cout << "Code : "; cin >> code;
   			deleteRecord(code);
   			break;

   		default:
   			return 0; 
    }
    }
    return 0;
}