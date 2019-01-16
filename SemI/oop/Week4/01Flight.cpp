//Ankit Apurv
//27_8_2018
//04
//01 Flight class

#include <iostream>
using namespace std;

class flight
{
    private:
        int number;
        char destination[5];
        float distance, fuel;

	void calculate_fuel()
	{	
    	if(distance <= 1000)
        	fuel = 500;
    	else if(distance > 1000 && distance <= 2000)
        	fuel = 1100;
    	else
        	fuel = 2200;
    	return;
	}


	public:
	void information_entry()
	{
    	cout << "\n\n";
    	cout << "Flight Number : "; cin >> number;
    	cout << "Destination : "; for(int i = 0; i < 5; i++) cin >> destination[i];
    	cout << "Distance : "; cin >> distance;
    	calculate_fuel();
    	return;
	}

	void display_info()
	{
    	cout << "\n\n";
    	cout << "Flight Number : " << number << "\n";
    	cout << "Destination : "; for(int i = 0; i < 5; i++) cout << destination[i]; cout << "\n";
    	cout << "Distance : " << distance << " km\n";
    	cout << "Fuel : " << fuel << " l\n";
    	return;
	}


	flight()
	{ fuel = 13.2; }

	flight(float f)
	{ fuel = f; }

	~flight()
	{}

};

int main(void)
{
    flight f1;
    f1.information_entry();
    f1.display_info();
    flight f2(9673.38);
    f2.display_info();
    f2.information_entry();
    f2.display_info();
    return(0);
}


