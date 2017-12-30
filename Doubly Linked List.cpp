//according to hasan vai github
#include<iostream>
#include<cstdio>
#define NULL 0
using namespace std;

struct node //here this is our list where we store and link values by using next and previous
{
    int number;
    node *next;
    node *previous;
};
node *head = NULL; //first we define two node type pointer
node *tail = NULL; //where we store address of node

node *get_newnode(int value)
{
    node *temp = new node();
    temp->number = value;
    temp->next = NULL;
    temp->previous = NULL;

    return temp;
}

void insert_at_tail(int value)
{
    node *newnode = get_newnode(value);

    if(head == NULL)
    {
        head = newnode; //head and tail  both stores newnode
        tail = newnode; //and its in the same linked list, there is no confusion

        return;
    }
    tail->next = newnode; //next store the new node
    newnode->previous = tail; //previous node of the new node store tail node

    tail = newnode; // now new node is our tail node
}

void insert_at_first(int value)
{
    node *newnode = get_newnode(value);

    if(head == NULL)
    {
        head = newnode;
        tail = newnode;

        return;
    }
    newnode->next = head;  //its simple that now newnode->next retains head
    head->previous = newnode; //and head->previous stores newnode

    head = newnode; //here now head is newnode
}

void insert_at_middle(int value, int position)
{
    node *newnode = get_newnode(value);

    if(head == NULL) //for the 1st element
    {
        head = newnode;
        tail = newnode;

        return;
    }

    node *temp = new node();
    temp = head;
    int i = 1;

    while((i < position-1) && temp->next!=NULL)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->previous = temp;

    if(temp->next) //if temp->next is not NULL
        temp->next->previous = newnode; //newnode will be the previous node of temp->next node

    temp->next = newnode;
}

void delete_node(int position) //delete any node of list according to position
{
    if(head == NULL) return;

    if(position == 1) //delete 1st(head)node
    {
        node *temp = head;
        head = head->next;

        if(head == NULL)
            tail = NULL;
        else
            head->previous = NULL;

        delete(temp);

        return;
    }

    node *temp = new node();
    node *tempanother = new node();
    int i = 1;

    temp = head;

    while((i < position) && temp->next!=NULL)
    {
        temp = temp->next;
        i++;
    }

    if(i == position)
    {
        tempanother = temp->previous;
        tempanother->next = temp->next;

        if(temp->next == NULL) //it means that we delete the last node.
            tail = tempanother;//now tempanother will be the last node
        else
            temp->next->previous = tempanother;

        delete(temp);
    }
    else printf("Desired position does not exixt!\n");
}

void printLinkedListForward()
{
    printf("\nYour updated linked list in FORWARD ORDAR:\n");

    node *mylist;
    mylist = head;

    while(1)
    {
        if(head == NULL || tail == NULL) break;

        printf("%d ", mylist->number);

        if(mylist == tail) break;

        mylist = mylist->next;
    }
    puts("\n");
}

void printLinkedListBackward()
{
    printf("\nYour full linked list in Reverse order:\n");

    node *mylist;
    mylist = tail;

    while(1)
    {
        if(head == NULL || tail == NULL) break;

        printf("%d ", mylist->number);

        if(mylist->previous == NULL) break;

        mylist = mylist->previous;
    }
    puts("\n");
}

int main()
{
    int a = 5,b = 15,c = 4, d = 67, e = 90, f = 87, g=99, h = 76, i= 7, j= 1;
    printf("Insert nodes at tail: %d %d %d\n", a, b, c);
    insert_at_tail(a);
    insert_at_tail(b);
    insert_at_tail(c);

    printLinkedListForward();

    printf("Insert nodes at front: %d\n", d);
    insert_at_first(d);

    printLinkedListForward();

    printf("Insert nodes at tail: %d\n", e);
    insert_at_tail(e);

    printLinkedListForward();

    printf("Insert nodes at front: %d\n", f);
    insert_at_first(f);

    printLinkedListForward();

    printf("Insert nodes at tail: %d, %d, %d, %d\n", g, h, i, j);
    insert_at_tail(g);
    insert_at_tail(h);
    insert_at_tail(i);
    insert_at_tail(j);

    printLinkedListForward();

    printLinkedListBackward();

    //now deleted function is start on
    int pos = 2, insertmidvalue = 500, deletepos = 4;

    printf("Insert node: %d at middele. Position: %d\n", insertmidvalue, pos);
    insert_at_middle(insertmidvalue, pos);

    printLinkedListForward();

    printf("Delete item of position number %d ", deletepos);
    delete_node(deletepos);

    printLinkedListForward();

    printf("Delete item of position number 1");
    delete_node(1);

    printLinkedListForward();

    printLinkedListBackward();

    return 0;
}
