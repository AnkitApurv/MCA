/*  @author Ankit Apurv
    @week 10 05/11/2018
    @desc db insert, delete, modify

    @NOTE the data conversion from uint32_t to std::ios_seekdir / streampos
    are due to older c++ standard gcc 4.1.8/4.8
    it works in gcc 8.1 - fixed for older version
    seekp(uint32_t offset, uint32_t location) works in newer standard
    seekp(uint32_t offset, std::beg/cur/end) works in older standard as well
*/

#include <iostream>
#include <fstream>
using namespace std;
/*
class item {
public:
    uint32_t id, qty, price;
    char name[5];
    //friend ofstream & operator << (ofstream &ot, item &i);
    //friend ifstream & operator >> (ifstream &it, item &i);
    item()
    {
        id = qty = price = 0;
        for(uint32_t i=0; i<5; i++)
            name[i] = '\0';
    }
    ~item() {}
};
*/
/*
ofstream & operator << (ofstream &ot, item &i)
{
    ot << i.id << i.qty << i.price << i.name;
    return ot;
}
ifstream & operator >> (ifstream &it, item &i)
{
    it >> i.id;
    it >> i.qty;
    it >> i.price;
    it >> i.name;
    return it;
}
*/

uint32_t count = 0;  //0 is for deleted records

void addRecord(bool isNew, uint32_t id)
{
    ofstream fl("04slfile.db", ios::app|ios::binary|ios::out);
    uint32_t qty, price;
    char name[5];
    if(isNew)
    {
        count++;
        id = count;
        cout << "ID : " << id << '\n';
    }
    else
        id = id;
    cout << "Quantity : "; cin >> qty;
    cout << "Price : "; cin >> price;
    cout << "Name : "; cin >> name;
    fl << id;
    fl << qty;
    fl << price;
    fl << name;
    fl.close();
}

uint32_t findRecord(uint32_t id, bool* found)
{
    ifstream fl("04slfile.db", ios::binary|ios::in);
    uint32_t currentId, location;
    fl.seekg(fl.beg);
    while(!*found && !fl.eof())
    {
        fl >> currentId;
        if(id==currentId)
        {
            *found = true;
            fl.seekg(-1, fl.cur);
            location = fl.tellg();
        }
        else
        {
            do
            {
                fl.seekg(1, fl.cur); //till end of name
            }
            while(fl.peek() != '\0' && !fl.eof());
            fl.seekg(1, fl.cur); //beginning of next record
        }
    }
    fl.close();
    return location;
}

void deleteRecord(uint32_t id)
{
    bool found = false;
    uint32_t location = findRecord(id, &found);
    ofstream fl("04slfile.db", ios::ate|ios::binary|ios::out);
    fl.seekp(location, fl.beg);
    id = 0;
    fl << id;
    return;
}

void modifyRecord(uint32_t id)
{
    deleteRecord(id);
    addRecord(false, id);
    return;
}

void retriveRecord(uint32_t id)
{
    bool found = false;
    uint32_t location = findRecord(id, &found);
    ifstream fl("04slfile.db", ios::binary|ios::in);
    fl.seekg(location, fl.beg);
    uint32_t qty, price;
    char name[5];
    fl >> id;
    fl >> qty;
    fl >> price;
    fl >> name;
    cout << "ID : " << id << '\n';
    cout << "Quantity : " << qty << '\n';
    cout << "Price : " << price << '\n';
    cout << "Name : " << name << '\n';
    return;
}

int main(void)
{
    cout<<"1. Add record\n";
    cout<<"2. Modify record\n";
    cout<<"3. Delete record\n";
    cout<<"4. Retrive record\n";
    int choice;
    uint32_t id;
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
        case 4:
            cout<<"ID : "; cin>>id;
            retriveRecord(id);
            break;

        default:
            return 0;
    }
    }
    return 0;
}
