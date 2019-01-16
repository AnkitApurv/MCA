//Ankit Apurv
//06_08_2018
//Week02
//05Fibonacci - Fibonacci sequence

#include <iostream>

using namespace std;

int main(void)
{
        unsigned int length, i = 2;

        cout << "Length : ";
        cin >> length;

        unsigned int seq[length];
        seq[0] = 0;
        seq[1] = 1;

        cout << endl << "Fibonacci Sequence :" << endl;
        cout << seq[0] << "\t" << seq[1] << "\t";
        for(i = 2; i <= length;  i++)
        {
                seq[i] = seq[i-1] + seq[i-2];
                cout << seq[i] << "\t";
        }

        return(0);
}
