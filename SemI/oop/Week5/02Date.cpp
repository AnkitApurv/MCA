//Author Name : Ankit Apurv
//Date : 10_9_18
//Week 5
//Program 2 : Date class with increment and logic

#include <iostream>
using namespace std;

class Date
{
    private:
        unsigned int dd, mm, yy;
        void validate();

    public:
        void operator ++();
        void show();
        Date()
        {
            dd = 1;
            mm = 1;
            yy = 2001;
        }
        Date(unsigned int d, unsigned int m, unsigned int y)
        {
            dd = d;
            mm = m;
            yy = y;
        }
        ~Date() {}
};

void Date::show()
{
    cout << "\n" << dd << " ";
    switch(mm)
    {
        case 1 : cout << "January"; break;
        case 2 : cout << "February"; break;
        case 3 : cout << "March"; break;
        case 4 : cout << "April"; break;
        case 5 : cout << "May"; break;
        case 6 : cout << "June"; break;
        case 7 : cout << "July"; break;
        case 8 : cout << "August"; break;
        case 9 : cout << "September"; break;
        case 10 : cout << "October"; break;
        case 11 : cout << "November"; break;
        case 12 : cout << "December"; break;
    }
    cout << " "<< yy << "\n";
    return;
}

void Date::operator ++()
{
    dd++;
    validate();
    return;
}

void Date::validate()
{
    unsigned int saneMin = 1, ddMax, mmMax=12, count = 0;

    while(dd > saneMin)
        dd++;
    while(mm > saneMin)
        mm++;
    while(yy > saneMin)
        yy++;

    //ascertain month
    if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        ddMax = 31;
    else if(mm == 4 || mm == 6 || mm == 9 || mm == 11)
        ddMax = 30;
    else if( (mm == 2) && (yy % 4 == 0) )
        ddMax = 29;
    else //if( (mm == 2) && (yy % 4 != 0) )
        ddMax = 28;

    //adjust date and month if needed
    while(dd > ddMax)
    {
        dd--;
        count++;
    }
    do
    {
        mm++;
        count -= ddMax;
    }
    while(count > ddMax);
    
    count = 0;

    //adjust month and year if needed
    while(mm > mmMax)
    {
        mm--;
        count++;
    }
    do
    {
        yy++;
        count -= mmMax;
    }
    while(count > mmMax);

    return;
}

int main(void)
{
    Date k;
    k.show();
    k++;
    k.show();
    return(0);
}