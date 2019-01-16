//23 Stack LL
//18_09_2018
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
        node* newNode;
        unsigned int nodeCount;

    public:
        LinkedList()
        {
            head = nullptr;
            newNode = nullptr;
            nodeCount = 0;
        }
        LinkedList(int val)
        {
            head = new node;
            head->value = val;
            head->link = nullptr;
            nodeCount = 1;

            newNode = nullptr;
        }
        void add(int val);
        int remove();
};

class Stack
{
    private:
        LinkedList l;
        int topIndex, size;

    public:
        Stack()
        {
            topIndex = -1;
            size = -1;
        }
        void getSize();
        bool push(int val);
        int pop();
        void show();
};

void LinkedList::add(int val)
{
    //add from head
    node* next = head;

    head = new node;
    head->value = val;
    head->link = next;
    nodeCount++;

    return;
}

int LinkedList::remove()
{
    //remove from head
    if(head == nullptr)
        return(0);

    node* toDelete = head;
    //head is now the next node
    head = head->link;
    nodeCount--;

    int val = toDelete->value;
    delete toDelete;

    return(val);
}

bool Stack::push(int value)
{
    if(topIndex == size-1)
        return(false);

    l.add(value);
    topIndex++;
    return(true);
}

int Stack::pop()
{
    if(topIndex == -1)
        return(0);

    //modify ll remove to not ask arguements and return removed value
    topIndex--;
    return(l.remove());
}

void Stack::show()
{
    if(topIndex == -1)
        return;
    int i;
    cout << "\nStack :\n\tIndex\t\tValue\n";
    for(i = topIndex; i >= 0; i--)
       // cout<< "\t" << i << "\t\t" << stack[i] << "\n";
    return;
}

void Stack::getSize()
{
    cout << "Stack Size : ";
    cin >> size;
    return;
}

int main(void)
{
    unsigned int choice;
    int val;
    system("clear");
    cout << "\n\n23 Stack\n\n";
    Stack s;
    s.getSize();
    cout << "1. Show\n";
    cout << "2. Push\n";
    cout << "3. Pop\n";
    cout << "4. Exit(default)\n";
    while(true)
    {
        cout << "\nChoice : ";
        cin >> choice;
        switch(choice)
        {
            case 1 :
                s.show();
                break;

            case 2 :
                cout << "Value : ";
                cin >> val;
                s.push(val);
                break;

            case 3 :
                val = s.pop();
                cout << "Value : " << val << "\n";
                break;

            default :
            case 4 :
                return(0);
        }
    }
    return(0);
}