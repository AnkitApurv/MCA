//Ankit Apurv
//13_08_2018
//03
//04Palindrome - check if given c style character array is palindrome

#include <iostream>
using namespace std;

bool checkPal(char a[], int l)
{
        bool isPalindrome = true;
        for(int i=0; i < l; i++)
        {
                if(a[i] != a[(l-1)-i])
                {
                        isPalindrome = false;
                        break;
                }
        }
        return(isPalindrome);
}

int main(void)
{
        int i, l;
        cout << "String Length : ";
        cin >> l;
        char a[l];
        cout << "Enter the string (one character at a time)\n";
        for(i=0; i<l; i++)
                cin >> a[i];
        if(checkPal(a, l))
                cout << "Palindrome\n";
        else
                cout << "Not Palindrome\n";
        return(0);
}
