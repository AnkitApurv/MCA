/*  @name 4BST.cpp
    @desc
    4.(a) Write a program to construct a binary  search tree using linked list. 
    4.(b) Given a binary search tree(BST) , write a method to count the number of leaf nodes in the BST.  The method takes one argument, the root of BST. 
    4.(c) Given a binary search tree(BST) , write a method to find the height of the  BST.  The method takes one argument, the root of BST. 
    @author Ankit Apurv 180970042
    @date 06/01/2019
*/


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

/*  @desc returns the pointer to root node
    @args
       void
    @return node type pointer
*/
    node* getRoot() { return root; }

/*  @desc shows the linkedlist
    @args
       void
    @return void
*/
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

/*  @desc insert node
    @args
       val : integer, value to store
    @return void
*/
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

/*
    @desc find total count of nodes
    @args
       n : node*
    @return count: integer

    @reference
https://www.geeksforgeeks.org/count-full-nodes-binary-tree-iterative-recursive/
*/
    int nodeCount(node* n)
    {
        if(n == nullptr)
            return 0;
        int count = 1;
        count += nodeCount(n->lc);
        count += nodeCount(n->rc);
        return count;
    }

/*
    @desc find max height of tree
    @args
       n : node*
    @return height: integer

    @reference
 maxDepth()
1. If tree is empty then return 0
2. Else
     (a) Get the max depth of left subtree recursively  i.e., 
          call maxDepth( tree->left-subtree)
     (a) Get the max depth of right subtree recursively  i.e., 
          call maxDepth( tree->right-subtree)
     (c) Get the max of max depths of left and right 
          subtrees and add 1 to it for the current node.
         max_depth = max(max dept of left subtree,  
                             max depth of right subtree) 
                             + 1
     (d) Return max_depth
    https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
*/
    int height(node* n)
    {
        if(n == nullptr)
            return 0;
        else
        {
            int lDepth = height(n->lc);
            int rDepth = height(n->rc);

            //+1 and depth instead of height because for empty node(or empty root) we return 0
            //and height is the count of nodes in longest path
            //depth is count of connection in longest path
            if(lDepth > rDepth)
                return lDepth+1;
            else
                return rDepth+1;
        }
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
    cout << "3. NodeCount\n";
    cout << "4. Height\n";
    cout << "5. Exit(default)\n";
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

            case 3 :
                cout << "Node Count : " << l.nodeCount(l.getRoot());
                break;

            case 4 :
                cout << "Height : " << l.height(l.getRoot());
                break;

            default :
            case 5 :
                return(0);
        }
    }
    return(0);
}