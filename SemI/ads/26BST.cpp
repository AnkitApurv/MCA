//26 Binary Search Tree
//10_10_2018
#include <iostream>
#include <cstdlib>
using namespace std;

//linked lists' concept can be used to build the tree


//every node is pointing to the next one till nullptr(at leaf)
class BST
{
private:
    struct node
    {
        node* lc;
        int value;
        node* rc;
    };

    node* root;

    void inorder(node *n)
    {
        if( n == nullptr ) return;
        inorder(n->lc);
        cout << n->value <<"\t";
        inorder(n->rc);
    }

    void preorder(node *n)
    {
        if( n == nullptr ) return;
        cout << n->value <<"\t";
        preorder(n->lc);
        preorder(n->rc);
    }

    void postorder(node *n)
    {
        if(n == nullptr) return;
        postorder(n->lc);
        postorder(n->rc);
        cout << n->value <<"\t";
    }

public:
    BST() { root = nullptr; }

    node* getRoot() { return root; }    //function

    void show()
    {
        if(root == nullptr)
        {
            cout << "Tree is empty\n";
            return;
        }

        cout << "Preorder\n";
        preorder(root);
        cout << "\n--------------------------------------\n\n";

        cout << "Inorder\n";
        inorder(root);
        cout << "\n--------------------------------------\n\n";

        cout << "Postorder\n";
        postorder(root);
        cout << "\n--------------------------------------\n\n";

        return;
    }

    void insert(int val)
    {
        node* newNode = new node; //creating

        //initializing
        newNode->lc = nullptr;
        newNode->value = val;
        newNode->rc = nullptr;

        //attaching leaf to tree
        if(root == nullptr)
        {
            root = newNode;
            return;
        }

        node* temp = root;
        if(newNode->value < root->value)
        {
            while((newNode->value < temp->value) && (temp->lc != nullptr))
                temp = temp->lc;
            temp->lc = newNode;
        }
        else
        {
            while((newNode->value >= temp->value) && (temp->rc != nullptr))
                temp = temp->rc;
            temp->rc = newNode;
        }
        return;
    }
};



int main(void)
{
    unsigned int choice;
    int val;
    system("clear");
    cout << "\n\n26 Binary Search Tree\n\n";
    cout << "1. Show the tree\n";
    cout << "2. Insert\n";
    cout << "3. Exit(default)\n";
    BST l;
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
                l.insert(val);
                break;

            default :
            case 3 :
                return(0);
        }
    }
    return(0);
}