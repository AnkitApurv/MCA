//24 Queue LL
//19_09_2018
#include <iostream>
#include <cstdlib>
using namespace std;

//every node is pointing to the next one till nullptr
class LinkedList
{
    private:
        struct node
        {
            int value;
            node* link;
        };
        node* head;
        node* current;
        unsigned int nodeCount;

    public:
        LinkedList()
        {
            head = nullptr;
            current = nullptr;
            nodeCount = 0;
        }
        void add(int);
        int remove(bool* success);
        void show(int);
};

class Queue
{
    private:
        LinkedList l;
        int fillCount, size;

    public:
        Queue()
        {
            fillCount = 0;
            size = 0;
        }
        void getSize();
        bool add(int);
        int remove(bool* success);
        bool show();
};

void LinkedList::add(int val)
{
    if(current != nullptr)
        while(current->link != nullptr)
            current = current->link;

    //if new ll, previous == nullptr, else previous == last node
    node* previous = current;

    current = new node;
    current->value = val;
    current->link = nullptr;

    if(previous != nullptr)
        previous->link = current;

    if(nodeCount == 0)
        head = current;

    nodeCount++;

    return;
}

int LinkedList::remove(bool *success)
{
    if(head == nullptr)
    {
        *success = false;
        return(INT8_MIN);
    }

    node* toDelete = head;
    head = head->link;
    nodeCount--;

    int val = toDelete->value;
    delete toDelete;
    *success = true;

    return(val);
}

void LinkedList::show(int fillCount)
{
    node* temp = head;
    cout << "\n\t" << "Index" << "\t\t" << "Value" << "\n";
    for(int i = 1; i <= fillCount && temp != nullptr; i++)
    {
        cout << "\n\t" << i << "\t\t" << temp->value;
        temp = temp->link;
    }
    cout << "\n";
    return;
}

bool Queue::add(int value)
{
    if(fillCount == size)
        return(false);

    l.add(value);
    fillCount++;
    return(true);
}

int Queue::remove(bool* success)
{
    if(fillCount == 0)
    {
        *success = false;
        return(0);
    }

    int val = l.remove(success);
    if(*success)
        fillCount--;
    return(val);
}

bool Queue::show()
{
    if(fillCount == 0)
        return(false);
    l.show(fillCount);
    return(true);
}

void Queue::getSize()
{
    cout << "Queue Size : ";
    cin >> size;
    return;
}

int main(void)
{
    int choice, val;
    bool success;
    system("clear");
    cout << "\n\n24 Queue\n\n";
    Queue s;
    s.getSize();
    cout << "1. Show\n";
    cout << "2. Add\n";
    cout << "3. Remove\n";
    cout << "4. Exit(default)\n";
    while(true)
    {
        success = false;
        cout << "\nChoice : ";
        cin >> choice;
        switch(choice)
        {
            case 1 :
            success = s.show();
                if( !success )
                    cout << "Queue underflow! nothing to disply.\n";
                break;

            case 2 :
                cout << "Value : ";
                cin >> val;
                success = s.add(val);
                if( !success )
                    cout << "Queue overflow! Cannot add.\n";
                break;

            case 3 :
                val = s.remove(&success);
                if( !success )
                {
                    cout << "Queue Underflow! Cannot remove.\n";
                    break;
                }
                cout << "Value : " << val << "\n";
                break;

            default :
            case 4 :
                return(0);
        }
    }
    return(0);
}