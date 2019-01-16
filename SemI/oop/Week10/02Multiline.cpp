/*
@author Ankit
 @date 29/10/2018
 @week 10
 @desc file i/o
Write a C++ program to create a multiline text file and then determine the following: 
Total number of characters, letters of the alphabet, digits, lines and spaces. 
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
    fstream fl("02slfile.txt", ios::in|ios::out);

    int i = 0, lineSize = 15;
    char a[lineSize] = "abra2ka \n dabra";
    fl << a;
    fl.seekg(fl.beg);
    fl.seekp(fl.beg);
    int charC = 0, lettersC = 0, digitsC = 0, linesC = 1, spacesC = 0;

    fl.getline(a, lineSize);
    while(i < lineSize)
    {
    	charC++;
    	if( ((a[i] >= 65) && (a[i] <= 90)) || ((a[i] >= 97) && (a[i] <= 122)) ) lettersC++;
    	if( (a[i] >= 48) && (a[i] <= 57)) digitsC++;
    	if(a[i] == '\n') linesC++;
    	if(a[i] == ' ') spacesC++;
    	i++;
    }
    cout << "Chars : " << charC << "\n";
    cout << "Letters : " << lettersC << "\n";
    cout << "Digits : " << digitsC << "\n";
    cout << "Lines : " << linesC << "\n";
    cout << "Spaces : " << spacesC << "\n";
    fl.close();
    return 0;
}