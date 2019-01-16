/*  @author Ankit Apurv
    @week 10 05/11/2018
    @desc db insert, delete, modify

    @NOTE the data conversion from int to std::ios_seekdir / streampos
    are due to older c++ standard gcc 4.1.8/4.8
    it works in gcc 8.1 - fixed for older version
    seekp(int offset, int location) works in newer standard
    seekp(int offset, std::beg/cur/end) works in older standard as well
*/

#include <iostream>
#include <fstream>
using namespace std;

const unsigned char s = ' ';
const unsigned char n = '\n';

void addRecord(bool isNew, int id)
{
    ofstream fl("04slfile.db", ios::app|ios::binary);
    char name[10] = { '\0' };
    int qty, price;
    char isDeleted = 'n';
    cout << "Name : "; cin >> name;
    if(isNew)
    {
        cout << "ID : "; cin >> id;
    }
    cout << "Quantity : "; cin >> qty;
    cout << "Price : "; cin >> price;
    fl << isDeleted << s << name << s << id << s << qty << s << price << n;
    fl.close();
}

streampos findRecord(int id, bool* found, int* size)
{
    fstream fl("04slfile.db", ios::binary);
    int currentId, location;
    fl.seekg(fl.beg);
    while(!*found && !fl.eof())
    {
        if(fl.peek() == 'y') break; //isDeleted, first attribute
        while(fl.peek() != s) fl.seekg(1, fl.cur);
        fl >> currentId;
        if(id==currentId)
        {
            *found = true;

            while( (fl.peek() != n) ) //|| (fl.tellg() != fl.beg) )
                fl.seekg(-1, fl.cur);
            fl.seekg(1, fl.cur);
            location = fl.tellg();

            while( (fl.peek() != n) || !fl.eof() )
                fl.seekg(1, fl.cur);
            //fl.seekg(-1, fl.cur); '\n' at the end of record is part of it
            int endLoc = fl.tellg();
            *size = endLoc-location;
        }
        else
        {
            do
            {
                fl.seekg(1, fl.cur);
            }
            while(fl.peek() != n && !fl.eof());
        }
    }
    fl.close();
    return location;
}

void deleteRecord(int id)
{
    bool found = false; int size = 0;
    int location = findRecord(id, &found, &size);
    fstream fl("04slfile.db", ios::ate|ios::binary|ios::out);
    fl.seekp(location, fl.beg);
    char isDeleted = 'y';
    fl.write(&isDeleted, 1);
    return;
}

void modifyRecord(int id)
{
    deleteRecord(id);
    addRecord(false, id);
    return;
}

int main(void)
{
    cout<<"1. Add record\n";
    cout<<"2. Modify record\n";
    cout<<"3. Delete record\n";
    int choice, id;
    while(true)
    {
    cout <<"\nChoice : "; cin >> choice;
    switch(choice)
    {
        case 1:
            addRecord(true, 0);
            break;
        case 2:
            cout<<"ID : "; cin>>id;
            modifyRecord(id);
            break;
        case 3:
            cout<<"ID : "; cin>>id;
            deleteRecord(id);
            break;

        default:
            return 0;
    }
    }
    return 0;
}
