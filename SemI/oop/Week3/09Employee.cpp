//Ankit Apurv
//13_08_2018
//03
//09 Employee Report
#include <iostream>
#include <string>

using namespace std;

const char tab = '\t';
const char newline = '\n';

struct Employee {
        int roll;
        string name;
        float basic;
        float da;
        float gross;
        float tax;
        float net;
};

Employee getInfo(void)
{
        Employee s;
        cout << "Employee Number : ";
        cin >> s.roll;
        cout << "Name : ";
        cin >> s.name;
        cout << "Basic Salary : ";
        cin >> s.basic;
        s.da = s.basic * 0.12;
        s.gross = s.basic + s.da;
        s.tax = s.gross * 0.18;
        s.net = s.gross - s.tax;
        return(s);
}

void showInfo(Employee s)
{
        system("clear");

        cout << "-------------------------------------------------------------------------------" << newline;
        cout << "Pay Slip : " << s.name << newline;
        cout << "Employee ID : " << s.roll << newline << newline;
        cout << "-------------------------------------------------------------------------------" << newline;
        cout << "Serial No." << tab << tab << "Catogary" << tab << tab << "Figure (in INR)" << newline;
        cout << "_______________________________________________________________________________" << newline;
        cout << "1" << tab << tab << tab << "Basic" << tab << tab << tab << s.basic << newline;
        cout << "2" << tab << tab << tab << "DA" << tab << tab << tab << s.da << newline;
        cout << "3" << tab << tab << tab << "Tax" << tab << tab << tab << s.tax << newline;
        cout << "_______________________________________________________________________________" << newline;
        cout << tab << tab << tab << "Gross :" << tab << tab << tab << s.gross << newline;
        cout << tab << tab << tab << "Net :" << tab << tab << tab << s.net << newline;
        cout << "-------------------------------------------------------------------------------" << newline;
        return;
}

int main(void)
{
        unsigned int sCount;
        cout << "Number of employees : ";
        cin >> sCount;

        struct Employee s;
        while(sCount > 0)
        {
                s = getInfo();
                showInfo(s);
                sCount--;
        }
        return(0);
}
