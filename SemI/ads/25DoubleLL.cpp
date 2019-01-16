//25 Double Linked List
//25_09_2018
#include <iostream>
#include <cstdlib>
using namespace std;

//every node is pointing to the next one till nullptr
class LinkedList
{
    private:
        struct node
        {
            node* previous;
            int value;
            node* next;
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
            head->previous = nullptr;
            head->value = val;
            head->next = nullptr;
            newNode = nullptr;
        }
        void show(bool);
        void add(int);
        void remove(int);
};

void LinkedList::show(bool fromFront)
{
    if(nodeCount == 0) return;
    cout << "Node Count : " << nodeCount << "\n";
    cout << "Count\t" << "Node\t\t" << "Value\t" << "Previous\t" << "Next\n";
    cout << "-----------------------------------------------------\n";

    if(fromFront)
    {
        node* p = head;
        for(unsigned int i = 1; i <= nodeCount; ++i)
        {
            cout << i << "\t" << p << "\t\t" << p->value << "\t" << p->previous << "\t" << p->next << "\n";
            p = p->next;
        }
    }
    else //fromRear
    {
        while(newNode->next != nullptr)
            newNode = newNode->next; //newNode is last
        node* p = newNode;

        for(unsigned int i = nodeCount; i >= 1; --i)
        {
            cout << i << "\t" << p << "\t\t" << p->value << "\t" << p->previous << "\t" << p->next << "\n";
            p = p->previous;
        }

    }

    cout << "-----------------------------------------------------\n";
    return;
}

void LinkedList::add(int val)
{
    //ascending order
    //newNode must be current last node at this point
    newNode = new node; //creating

    //initializing
    newNode->previous = nullptr;
    newNode->value = val;
    newNode->next = nullptr;

    if(nodeCount == 0) //new linkedlist
        head = newNode;                     //newNode is last
    else if(nodeCount == 1) //only head
    {
        if(head->value > newNode->value) //add in front of node
        {
            head->previous = newNode;
            newNode->next = head;

            head = head->previous;          //head is first
            newNode = newNode->next;        //newNode is last
        }
        else //add after head
        {
            head->next = newNode;
            newNode->previous = head;       //newNode is last
        }
    }
    else //nodeCount > 1
    {
        //same as nodeCount==1, repetition for logic and clarity
        if(head->value > newNode->value) //add in front of head
        {
            head->previous = newNode;
            newNode->next = head; //adding

            head = head->previous;          //head is first
        }
        else //add somewhere in-between the chain
        {
            node* temp = head;

            //finding correct location
            while((temp->next != nullptr) &&
                  (temp->value < newNode->value))
                temp = temp->next;

            //making the newNode part of the chain
            newNode->previous = temp;
            newNode->next = temp->next;

            //realign the chain
            temp->next = newNode;

            if(newNode->next != nullptr)
                (newNode->next)->previous = newNode;
        }
        while(newNode->next != nullptr)
            newNode = newNode->next; //newNode is last
    }
    nodeCount++;
    return;
}

void LinkedList::remove(int val)
{
    //find the node toDelete by value
    node* toDelete = head;
    while( (toDelete->value != val) && (toDelete->next != nullptr) )
        toDelete = toDelete->next;

    //node not found
    if(toDelete->value != val || toDelete == nullptr)
    {
        cout << "Node Value not found!\n";
        return;
    }

    //else node has been found
    if(toDelete == head) //toDelete first node
        head = head->next; //2nd node is now the head
    else //toDelete is any other node in the chain
    {
        (toDelete->previous)->next = toDelete->next;
        if(toDelete->next != nullptr)
            (toDelete->next)->previous = toDelete->previous;
    }

    nodeCount--;
    delete toDelete;

    newNode = head;
    while(newNode->next != nullptr)
        newNode = newNode->next; //newNode is last

    return;
}



int main(void)
{
    unsigned int choice;
    int val;
    system("clear");
    cout << "\n\nLinked List\n\n";
    cout << "1. Show from front\n";
    cout << "2. Show from rear\n";
    cout << "3. Add\n";
    cout << "4. Remove\n";
    cout << "5. Exit(default)\n";
    LinkedList l;
    while(true)
    {
        cout << "\nChoice : ";
        cin >> choice;
        switch(choice)
        {
            case 1 :
                l.show(true);
                break;

            case 2:
                l.show(false);
                break;

            case 3 :
                cout << "Value : ";
                cin >> val;
                l.add(val);
                break;

            case 4 :
                cout << "Value : ";
                cin >> val;
                l.remove(val);
                break;

            default :
            case 5 :
                return(0);
        }
    }
    return(0);
}