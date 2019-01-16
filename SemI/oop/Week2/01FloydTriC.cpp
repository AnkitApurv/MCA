//Ankit Apurv
//06_08_2018
//Week02
//01FloydTriangle - Floyd's Triangle - C

#include <iostream>

using namespace std;

int main(void)
{
        unsigned int i, j, nLines, nChars;
        char number = 'A';

        cout << "Number of lines : ";
        cin >> nLines;
        cout << endl;

        nChars = nLines;

        for(i = 0; i < nLines; i++)
        {
                for(j = 0; j < nChars; j++)
                {
                        cout << number << "\t";
                }
                cout << endl;
                nChars--;
        }
        return(0);
}
