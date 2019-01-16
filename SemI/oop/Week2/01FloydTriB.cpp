//Ankit Apurv
//06_08_2018
//Week02
//01FloydTriangle - Floyd's Triangle - B

#include <iostream>

using namespace std;

int main(void)
{
        unsigned int i, j, nLines, nChars;
        char number = '*';

        cout << "Number of lines : ";
        cin >> nLines;
        cout << endl;

        nChars = 1;

        for(i = 0; i < nLines; i++)
        {
                for(j = 0; j < nChars; j++)
                {
                        cout << number << "\t";
                }
                cout << endl;
                nChars++;
        }
        return(0);
}
