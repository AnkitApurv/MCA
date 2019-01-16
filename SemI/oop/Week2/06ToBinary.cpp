//Ankit Apurv
//06_08_2018
//Week02
//06ToBinary - Coverting decinal to binary without array

#include <iostream>

using namespace std;

int main(void)
{
        //binary array is 512 ints long to accomodate upto 64bit decimals (64*8)
        unsigned int decimal, binary[sizeof(unsigned int)*8], i = 0;

        cout << "Positive Decimal : ";
        cin >> decimal;

        while(decimal > 0)
        {
                binary[i] = decimal % 2;
                decimal /= 2;
                i++;
        }

        cout << "In Binary :" << endl;
        while(i > 0)
        {
                cout << binary[i-1] << "\t";
                i--;
        }
        return(0);
}
