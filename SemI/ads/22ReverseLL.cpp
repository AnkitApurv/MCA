//22 Linked List
//14_09_2018
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
        void show();
        void add(int);
        void remove(int);
        void reverse(node* , node*);
        void reverseL();
        node* getHead() { return head; }
};

void LinkedList::show()
{
    if(nodeCount == 0)
    {
        cout << "Linked list is empty!\n";
        return;
    }
    node* p = head;
    cout << "Node Count : " << nodeCount << "\n";
    cout << "Count\t" << "Node\t\t" << "Value\t" << "Link\n";
    cout << "-----------------------------------------------------\n";
    for(unsigned int i = 1; i <= nodeCount; ++i)
    {
        cout << i << "\t" << p << "\t" << p->value << "\t" << p->link << "\n";
        p = p->link;
    }
    cout << "-----------------------------------------------------\n";
    return;
}

void LinkedList::add(int val)
{
    //ascending order

    newNode = new node;
    newNode->value = val;
    newNode->link = nullptr;

    if(nodeCount == 0) //new initialization
        head = newNode;
    else if(nodeCount == 1) //only head
    {
        if(head->value > newNode->value) //add in front of node
        {
            newNode->link = head;
            head = newNode;
        }
        else //add after node
            head->link = newNode;
    }
    else //nodeCount > 1
    {
        //same as nodeCount==1, repetition for logic and clarity
        if(head->value > newNode->value) //add in front of head
        {
            newNode->link = head;
            head = newNode;
        }
        else //add somewhere in-between the chain
        {
            node* previous = head;
            node* next = previous->link;

            //finding correct location
            while( (previous->value < newNode->value) && 
                ( (next != nullptr) && (next->value < newNode->value) ) )
            {
                previous = previous->link;
                next = previous->link;
            }

            //making the newNode part of the chain
            previous->link = newNode;
            newNode->link = next;
        }
    }
    nodeCount++;
    return;
}

void LinkedList::remove(int val)
{
    //find the node toDelete by value
    node* toDelete = head;
    while( (toDelete->value != val) && (toDelete->link != nullptr) )
        toDelete = toDelete->link;

    //node not found
    if(toDelete->value != val)
    {
        cout << "Node Value not found!\n";
        return;
    }

    //else node has been found
    if(toDelete == head) //toDelete first node
        head = (head->link); //2nd node is now the head
    else //toDelete any other node in the chain
    {
        //iterating upto just before toDelete
        node* previous = head;
        while(previous->link != toDelete)
            previous = previous->link;

        previous->link = toDelete->link; //previous node now links to the node after toDelete
    }

    nodeCount--;
    delete toDelete;
    return;
}


void LinkedList::reverse(node* curr, node* prev)
{
	if(curr == nullptr)
		head = prev;
	else
	{
		reverse(curr->link, curr);
		curr->link = prev;
	}
    return;
}

void LinkedList::reverseL()
{
    while(newNode->link != nullptr)
        newNode = newNode->link;
    node* tempTail = newNode; //head for reverse
    node* tempHead = head; //tail for reverse
/*
Explanation :
head is the first element for now
newNode is the last element for now
back-up the head and tail address of the original ll

head iterates over nodes till it's the previous node for newNode
newNode->link = head means establish link with previous node
newNode = newNode->link means it now is it's formerly previous node
if head was the actual original head, it must now point to null
reversal is done!

reset head to original tail value from tempTail which is reversd head
reset newNode to original head value from tempHead which is reversed tail
*/
    while(head->link != nullptr)
    {
        head = tempHead;
        while(head->link != newNode)
            head = head->link;

        newNode->link = head;
        newNode = newNode->link;
        if(head == tempHead)
            head->link = nullptr;
    }
    head = tempTail;
    newNode = tempHead;
    return;
}



int main(void)
{
    unsigned int choice;
    int val;
    system("clear");
    cout << "\n\nLinked List\n\n";
    cout << "1. Show\n";
    cout << "2. Add\n";
    cout << "3. Remove\n";
    cout << "4. Reverse\n";
    cout << "5. Exit(default)\n";
    LinkedList l;
    while(true)
    {
        cout << "\nChoice : ";
        cin >> choice;
        switch(choice)
        {
            case 1 :
                l.show();
                break;

            case 2 :
                cout << "Value : ";
                cin >> val;
                l.add(val);
                break;

            case 3 :
                cout << "Value : ";
                cin >> val;
                l.remove(val);
                break;

            case 4:
                l.reverse(l.getHead(), nullptr);
                break;

            default :
            case 5 :
                return(0);
        }
    }
    return(0);
}
