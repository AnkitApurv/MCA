/*  @name 1SumOfDigits.cpp
	@desc to find the sum of the digits of a number using recursion.
	@author Ankit Apurv 180970042
	@date 04/01/2019
*/

#include <iostream>
using namespace std;


/*  @desc computes sum of digits recursively
	@args
		num : integer, number whose digits are to be added
		sum : integer, variable to store and return the result
	@return integer, sum of digits of the given number
*/
int rSum(int num, int sum)
{
	if(num > 0)
	{
		if(num >= 10)
		{
			int i = num % 10;
			num -= i;
			num /= 10;
			sum += i;
		}
		else
		{
			sum += num;
			num  = 0;
		}
		return rSum(num, sum);
	}
	else
	{
		return sum;
	}
}

/*  @desc main
	@args
		void
	@return exit code
*/
int main(void)
{
	int n, s = 0;
	cout << "Number : ";
	cin >> n;
	cout << "\nSum : " << rSum(n, s) << "\n";
	return 0;
}