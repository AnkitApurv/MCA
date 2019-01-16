//21 Linked List
//05_09_2018
//NOTE : CONVERT TO CPP
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//every node is pointing to the next one till null

struct node
{
    int value = 0;
    node* link = null;
};

void insert(node* head, node* thisNode, int val)
{
    if(head != null)
    {
        node* i = head;
        while(i->link != null)
            i = i->link;
        i->link = thisNode;
        thisNode->value = val;
    }
    else
        thisNode->value = val;
    return;
}

int delete(node* head, int pos)
{
    int val, i;
    node* n = head, tn;
    for(i = 1; i < pos; i++)
    {
        n = n->link;
    }
    n = tn;
    n->link = null;
    tn->value = val;
    free(*tn);
    return(val);
}

void show(node* head)
{
    node* i = head;
    do
    {
        printf("%d\t", i->value);
        i = i->link;
    }
    while(i->link != null)
    return;
}

int main(void)
{
    unsigned int choice;
    bool isNew = true;
    node head;
    printf("\n\nLinked List\n");
    while(true)
    {
        printf("\nChoice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 :
                show(&head);
                break;

            case 2 :
                int value;
                printf("\nValue : ");
                scanf("%d", &val);
                if(isNew)
                {
                    insert(null, &head, val);
                    isNew = false;
                }
                else
                    insert(&head, &thisNode, val);
                //last problem how to have multiple node variable memory allocations
                //and not overwrite the previous one.
                break;

            case 3 :
                unsigned int pos;
                printf("Position : ");
                scanf("%u", &pos);
                printf("Removed : %d\n", delete(&head, pos));
                break;

            default :
            case 4 :
                return(0);
        }
    }
    return(0);
}