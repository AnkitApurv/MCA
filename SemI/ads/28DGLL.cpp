/*  @author Ankit Apurv
    @desc Directed Graph vi Adjacency List
    @date 16/10/2018
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class LinkedList
{
    private:
        struct node
        {
            int value;
            node* link;
        };
        node* head;

    public:
        LinkedList() { head = nullptr; }
        void show()
        {
            if(head != nullptr)
            {
                node* p = head;
                while(true)
                {
                    if(p == nullptr) break;
                    cout << p->value << "->";
                    p = p->link;
                }
            }    
            cout << "\\";
            return;
        }
        void add(int val)
        {
            node* newNode = new node;
            newNode->value = val;
            newNode->link = nullptr;

            if(head == nullptr) //new initialization
                head = newNode;
            else
            {   
                //finding correct location
                node* last = head;
                while(last->link != nullptr) { last = last->link; }
                //making the newNode part of the chain
                last->link = newNode;
            }
            return;
        }
};

class DGraph
{
    private:
        unsigned int edges;
        LinkedList l[10];

    public:
        DGraph() {};

        void create(void)
        {
            cout << "Number of edges : ";
            cin >> edges;
            int from = 0, to = 0;

            cout << "Specify the vertices (from <space> to)\n";
            while(from != -1 || to != -1)
            {
                cout << "Vertex : "; cin >> from >> to;
                if( ((from < 1) || (from > edges)) || ((to < 1) || (to > edges)) ) { break; }
                l[from].add(to);
            }
        };

        void display(void)
        {
            for(unsigned int i = 1; i <= edges; i++)
            {
                cout << i << "->";
                l[i].show();
                cout << "\n";
            }
        };
};




int main(void)
{
    system("clear");
    cout << "28 Directed Graph via Adjacency List\n\n";
    DGraph g;
    g.create();
    g.display();
    return 0;
}