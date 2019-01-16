//Ankit Apurv
//13_08_2018
//03
//03Swap - to swap two arrays without returning

#include <iostream>
using namespace std;

void swap(int a[], int b[], int l)
{
        int i, s[l];
        for(i = 0; i < l; i++)
        {
                s[i] = a[i];
                a[i] = b[i];
                b[i] = s[i];
        }
        return;
}

int main(void)
{
        unsigned int l, i;
        system("clear");
        cout << "Length (Integer array): ";
        cin >> l;
        int a[l], b[l];
        for(i = 0; i < l; i++)
        {
                cout << "a[" << i <<"] : ";
                cin >> a[i];
        }
        cout << "\n";
        for(i = 0; i < l; i++)
        {
                cout << "b[" << i <<"] : ";
                cin >> b[i];
        }
        swap(a, b, l);
        cout << "\nAfter Swap :\n";
        for(i = 0; i < l; i++)
                cout << "a[" << i <<"] : " << a[i] << "\t";
        cout << "\n";
        for(i = 0; i < l; i++)
                cout << "b[" << i <<"] : " << b[i] << "\t";
        cout << "\n";
        return(0);
}
