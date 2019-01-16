//Ankit Apurv
//27_8_18
//04
//02 BankAcc

#include <iostream>
using namespace std;

enum class accType { New, Savings, Fixed, Current };

class BankAcc
{
    private:
        char name[10];
        int number;
        accType type;
        float amount;

    public:
        ~BankAcc() {}
        void deposit(float f);
        void display(int accNo);
        friend void withdraw(BankAcc *b, float f);

	BankAcc()
	{
    	for(int i=0; i<10; i++)
        	name[i] = '0';
    	number = 0;
    	type = accType::New;
    	amount = 0;
	}

	BankAcc(char na[], int nu, accType ty, float amt)
	{
    	for(int i = 0; i < 10; i++)
        	name[i] = na[i];
    	number = nu;
    	type = ty;
    	amount = amt;
	}
};

void withdraw(BankAcc *b, float f)
{
    if(b->amount < f)
		cout << "\nOverdraw! Balance : " << b->amount << "\n";
    else
	{
		b->amount -= f;
		cout << "\nWithdrawn : " << f << "\nBalance : " << b->amount;
	}
    return;
}

void BankAcc::deposit(float f)
{
    amount += f;
    return;
}

void BankAcc::display(int accNo)
{
    if(number == accNo)
    {
        cout << "\nHolder's Name : ";
        for(int i=0; i<10; i++)
            cout << name[i];
        cout << "\nAccount Balance : " << amount << "\n";
    }
    else cout << "\nAccount not found!\n";
    return;
}

int main(void)
{
	char x[4];
	int i;
	for(i = 0; i < 4; i++)
		x[i] = 'w';
	BankAcc a(x, 101, accType::Savings, 10000);
	withdraw(&a, 1000);
	a.display(101);
	return(0);
}
