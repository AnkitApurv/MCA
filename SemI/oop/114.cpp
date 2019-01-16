#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Items
{
    string name;
    int id,qty;
    float price;
    int maxid;

        public:
                Items()
                {
                        name="";
                        price=0;
                        qty=0;
                        maxid=100;
                }

                int checkid(int itemid)
                {
                        return (itemid<100||itemid>=maxid);
                }

                int validate(int itemid)
                {
                        return itemid==id;
                }

                void getItem()
                {
                        cout<<"\nEnter Details for ItemID-"<<maxid;
                        id=maxid++;
                        cout<<"\nEnter Items Name : ";
                        cin>>name;
                        do{
                                cout<<"\nEnter Quantity   : ";
                                cin>>qty;
                                if(qty>1000||qty<0)
                                        cout<<"Enter a valid qty!!...";
                        }while(qty>1000||qty<0);

                        do{
                                cout<<"\nEnter Unit price : ";
                                cin>>price;
                                if(price<1||price>10000)
                                        cout<<"Enter a valid item price!!...";
                        }while(price<1||price>10000);
                }
                void update()
                {
                        cout<<"\nUpdate Details for ItemID-"<<id;
                        do{
                                cout<<"\nEnter Quantity   : ";
                                cin>>qty;
                                if(qty>1000||qty<0)
                                        cout<<"Enter a valid qty!!...";
                        }while(qty>1000||qty<0);

                        do{
                                cout<<"\nEnter Unit price : ";
                                cin>>price;
                                if(price<1||price>10000)
                                        cout<<"Enter a valid item price!!...";
                        }while(price<1||price>10000);
                }

                void deleteREC()
                {
                        id=0;
                }

                void display()
                {
                        cout<<"\nItem details -";
                        cout<<"\nItem ID     : "<<id;
                        cout<<"\nItem Name   : "<<name;
                        cout<<"\nQuantity    : "<<qty;
                        cout<<"\nUnit Price  : "<<price;
                }
};
int main()
{
        system("clear");
        int ch;
        int id,flg=0;
        Items i1;
        ifstream i_file;
        ofstream o_file("ex4.txt");
        o_file.close();
        while(1)
        {
                cout<<"\n\n1)Enter a new Item detail\n2)Update an item\n3)Delete a item\n4)Display item\n\nEnter your choice: ";
                cin>>ch;
                switch(ch)
                {
                        case 1:
                                        o_file.open("ex4.txt",ios::app|ios::binary);
                                                //file.clear();
                                                //file.seekp(0,ios::end);
                                        i1.getItem();
                                        o_file.write((char*)&i1,sizeof(i1));
                                        o_file.close();
                                        cout<<"\nItem Details inserted.";
                                        break;
                        case 2:

                                        cout<<"\nEnter an Itemid : ";
                                        cin>>id;
                                        if(i1.checkid(id))
                                                cout<<"\nInvalid ID!!....";
                                        else
                                        {
                                                i_file.open("ex4.txt",ios::binary);
                                                i_file.seekg(sizeof(i1)*(id-100));
                                                i_file.read((char*)&i1,(sizeof(i1)));
                                                i1.update();
                                                i_file.close();

                                                o_file.open("ex4.txt",ios::binary);
                                                o_file.seekp(sizeof(i1)*(id-100));
                                                o_file.write((char*)&i1,(sizeof(i1)));
                                                o_file.close();
                                                cout<<"\nItem Details updated.";
                                        }
                                        break;
                        case 3:
                                        cout<<"\nEnter an Itemid : ";
                                        cin>>id;
                                        if(i1.checkid(id))
                                                cout<<"\nInvalid ID!!....";
                                        else
                                        {

                                                o_file.open("temp.txt",ios::binary);
                                                i_file.open("ex4.txt",ios::binary);
                                                while(!i_file.eof())
                                                {
                                                        i_file.seekg(sizeof(i1)*(id-100));
                                                        i_file.read((char*)&i1,(sizeof(i1)));
                                                        if(i1.validate(id))
                                                                break;
                                                        else
                                                                o_file.write((char*)&i1,sizeof(i1));
                                                }
                                                i_file.seekg(sizeof(i1)*((id+1)-100));
                                                while(!i_file.eof())
                                                {
                                                        o_file.write((char*)&i1,sizeof(i1));
                                                }
                                                cout<<"\nItem Deleted....";
                                                o_file.close();
                                                i_file.close();
                                                remove("ex4.txt");
                                                rename("temp.txt","e4.txt");
                                        }
                                        break;
                        case 4:
                                        cout<<"\nEnter an Itemid : ";
                                        cin>>id;
                                        if(i1.checkid(id))
                                                cout<<"\nInvalid ID!!....";
                                        else
                                        {
                                                flg=0;
                                                i_file.open("e4.txt",ios::binary);
                                                i_file.seekg(sizeof(i1)*(id-100));
                                                while(!i_file.eof()&&flg==0)
                                                {
                                                        i_file.read((char*)&i1,(sizeof(i1)));
                                                        if(i1.validate(id))
                                                        {
                                                                i1.display();
                                                                flg=1;
                                                        }
                                                }
                                                if(flg==0)
                                                        cout<<"\nInvalid ID!!....";
                                                i_file.close();
                                        }
                                        break;
                        default :exit(0);
        }
        }
        cin.ignore();
        getchar();
     }