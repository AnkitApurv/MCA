//Ankit Apurv
//27_8_18
//04
//03 Player

#include <iostream>
using namespace std;

class Player
{
    private:
        int code;
        char name[10];
        int runs;
        int innings;
        int notOut;

    public:
        void setInfo();
        float getAvg();
        int getRuns();
        void getName();
        friend int operator +(Player p1, Player p2);
        friend bool operator >(Player p1, Player p2);
        friend void sort (Player p[], int count);

	Player()
	{
    	code = 0;
    	runs = 0;
    	innings = 0;
    	notOut = 0;
	}

	~Player() {}
};


float Player::getAvg()
{
    return runs/innings;
}

int Player::getRuns()
{
    return runs;
}

void Player::getName()
{
    for(char x : name)
        cout << x;
    cout << "\n";
    return;
}

void Player::setInfo()
{
    cout << "\n\n";
    cout << "Name : ";
    for(int i=0; i<10; i++)
        cin >> name[i];
    cout << "Code : "; cin >> code;
    cout << "Runs : "; cin >> runs;
    cout << "Innings : "; cin >> innings;
    cout << "Not Out : "; cin >> notOut;
    return;
}

int operator +(Player p1, Player p2)
{
    return(p1.runs + p2.runs);
}

bool operator >(Player p1, Player p2)
{
	return(p1.runs > p2.runs ? true : false);
}

void sort(Player p[], int count)
{
    Player temp;
    for(int i=0; i<count-1; i++)
    {
        if(p[i].getRuns() > p[i+1].getRuns())
        {
            temp = p[i];
            p[i] = p[i+1];
            p[i+1] = temp;
        }
    }
    return;
}

int main(void)
{
    Player p[3];
    for(Player x : p)
    {
        x.setInfo();
    }
    cout << "Average - Player 1 : " << p[0].getAvg() << "\n";
    for(Player x : p)
    {
        x.getAvg();
    }
    sort(p, 5);
    for(Player x : p)
    {
        x.getRuns();
    }
}