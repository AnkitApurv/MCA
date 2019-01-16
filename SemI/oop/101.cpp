#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
    fstream fl("01slfile.txt");
    fl << "abra ka dabra";
    char a[14];
    int i = 0, count = 0, choice;

    cout << "Convert upper to lower case and vice versa.\n";
    cout << "Display contents.\n";
    cout << "Determine count of 'a'.\n";

    while(true)
    {

    cout << "\n\nChoice : "; cin >> choice;
    if(fl.eof()) fl.seekg(ios::beg);
    i = 0, count = 0;

    switch(choice)
    {
        case 1:
            fl.get(a, 14);
            while(a[i] != '\0')
            {
                if(a[i] > ) a[i] += 31;
				else a[i] -= 31;
				i++;
            }
            while(! fl.eof())
            {
                fl << a[i];
                i++;
            }
            break;

        case 2:
            while(! fl.eof())
            {
                cout << fl;
            }
            break;

        case 3:
            while(! fl.eof())
            {
                fl >> a[i];
                i++;
            }
            while(a[i] != '\0')
            {
                if(a[i] == 'a')
                    count++;
                i++;
            }
            cout << "Count : " << count;
            break;

        case 4: default: return 0;
    }

    }
    return 0;
}