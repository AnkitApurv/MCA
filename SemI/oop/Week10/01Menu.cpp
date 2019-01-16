/*
@author Ankit
 @date 29/10/2018
 @week 10
 @desc file i/o
Write a menu driven C++ program to create a single line text file and then implement the following: 
a) Convert every lower case letter to upper case and upper case letter to lower case. 
b) Display the content of the file.  
c) Determine how many times a character ‘a’ is present in the file. 
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
    fstream fl("01slfile.txt", ios::in|ios::out|ios::trunc);
    /*if(! fl)
    {
        std::cerr<<"Cannot open the output file."<<std::endl;
        return 1;
    }*/
    
    int i, count, choice, lineSize = 15;
    char a[lineSize] = "\nabra ka dabra";
    fl << a;

    cout << "1. Convert upper to lower case and vice versa.\n";
    cout << "2. Display contents.\n";
    cout << "3. Determine count of 'a'.\n";

    while(true)
    {

    cout << "\n\nChoice : "; cin >> choice;
    fl.seekg(fl.beg);
    fl.seekp(fl.beg);
    i = 0, count = 0;

    switch(choice)
    {
        case 1:
        	i = 0, count = 0;
        	fl.seekg(fl.beg);
    		fl.seekp(fl.beg);
            fl.getline(a, lineSize);
            while(i < lineSize)
            {
                if( (a[i] >= 65) && (a[i] <= 90) )
                	a[i] += 32;	//upper to lower
				else if( (a[i] >= 97) && (a[i] <= 122) )
                	a[i] -= 32; //lower to upper
				i++;
            }
            for(i = 0; i < lineSize; i++)
            	fl << a[i];
            break;

        case 2:
        	i = 0, count = 0;
        	fl.seekg(fl.beg);
    		fl.seekp(fl.beg);
            fl.getline(a, lineSize);
            for(int i = 0; i < lineSize; i++)
            	cout << a[i];
            break;

        case 3:
        	i = 0, count = 0;
        	fl.seekg(fl.beg);
   			fl.seekp(fl.beg);
            fl.getline(a, lineSize);
            while(i < lineSize)
            {
                if(a[i] == 'a')
                    count++;
                i++;
            }
            cout << "Count : " << count;
            break;

        default:
        	fl.close();
        	return 0;
    }
    }
    return 0;
}