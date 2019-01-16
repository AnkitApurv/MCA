/*
@author Ankit
 @date 29/10/2018
 @week 10
 @desc file i/o
Write a C++ program to create an employee database and store the following information: Name, Employee id, Department, Designation, Basic
 salary Then accept an employee id from the keyboard and generate the salary slip for that employee. Use suitable formulas to calculate DA, 
 HRA, GROSS PAY, INCOME TAX and NET PAY. Make use of random access file concept. (Employee id should be generated automatically). 
*/
#include <iostream>
#include <fstream>
using namespace std;

//ifstream - read only
//ofstream - write only
//ascii 30 - record separator

const unsigned char recordSep = '\n';
const unsigned char unitSep = ' ';

void addRecord(void)
{
	ofstream fl("03slfile.db", ios::app|ios::binary);
	char name[10] = {'\0'};
	cout << "Name : "; cin >> name;
	int id;
	cout << "ID : "; cin >> id;
	char dept, desig;
	cout << "Dept : "; cin >> dept;
	cout << "Desig : "; cin >> desig;
	int basic;
	cout << "Basic : "; cin >> basic;
	fl << name << unitSep << id << unitSep << dept << unitSep << desig << unitSep << basic << recordSep;
	fl.close();
}

int getBasic(int id, bool* found)
{
	ifstream fl("03slfile.db", ios::binary);
	int basic = 0, currentId = 0;
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
			//skipping to basic
			int count = 0;
			while(count < 3)
			{
				if(fl.peek() == unitSep) count++;
				fl.seekg(1, fl.cur);
			}
			fl >> basic;
		}
		fl.seekg(1, fl.cur); //to the beginning of next record
	}
	fl.close();
	return basic;
}

void paySlip(int id)
{
	bool found = false;
	int basic = getBasic(id, &found);
	if(!found)
	{
		cout << "Employee not found!\n";
		return;
	}
	int da = basic * 0.1;
	int hra = basic * 0.05;
	int gross = basic + da + hra;
	int tax = gross * 0.25;
	int net = gross - tax;
	cout << "ID : " << id << "\n";
	cout << "Basic : " << basic << "\n";
	cout << "DA : " << da << "\n";
    cout << "HRA : " << hra << "\n";
    cout << "Gross : " << gross << "\n";
    cout << "Tax : " << tax << "\n";
    cout << "Net : " << net << "\n\n";
    return;
}

int main(void)
{
	cout << "1. Add Records\n";
	cout << "2. Pay Slip\n";
    int choice, id;
    while(true)
    {
    cout << "\nChoice : "; cin >> choice;
    switch(choice)
    {
    	case 1:
    		addRecord();
    		break;

    	case 2:
    		cout << "ID : "; cin >> id;
   			paySlip(id);
   			break;

   		default:
   			return 0; 
    }
    }
    return 0;
}