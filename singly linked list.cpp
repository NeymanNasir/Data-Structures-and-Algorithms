//according to shafayet vai blog and hasan vai blog........
#include<iostream>
#include<cstdio>
#define NULL 0
using namespace std;

struct node //here this is our list where we store and link values by using next
{
    int roll;
    node *next;
};
node *root = NULL;

void insert_at_last(int roll)//Insert an item at last position of linked list
{
    if(root == NULL)
    {
        root = new node();
        root->roll = roll;
        root->next = NULL;
    }
    else
    {
        node *current_node = root;
        while(current_node->next != NULL)
        {
            current_node = current_node->next ;
        }
        node *newnode = new node();
        newnode->roll = roll;
        newnode->next = NULL;

        current_node->next = newnode;//according to root we contain next node
    }
}

void insert_at_first(int roll)//Insert an item at the first position of Linked List
{
    node *temp = new node();
    temp->roll = roll;
    temp->next = root;

    root = temp;
}

void insert_after_key(int key, int roll) // insert roll after any item
{
    node *current_node = root;

    while(current_node != NULL)
    {
        if(current_node->roll == key)
        {
            node *newnode = new node();
            newnode->roll = roll;
            newnode->next = current_node->next;

            current_node->next = newnode;//current node->next takes new node which contains the after current node
            break;
        }
        else
            current_node = current_node->next;
    }
}

void delete_node(int roll)
{
    node *current_node = root;
    node *previous_node = NULL;
    while(current_node->roll != roll)
    {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if(current_node == root)
    {
        node *temp = root;
        root = root->next;
        delete(temp);
    }
    else
    {
        previous_node->next = current_node->next;
        delete(current_node);
    }
}

void search_roll(int roll)
{
    node *current_node = root;
    int flg = 0;

    while(current_node != NULL)
    {
        if(current_node->roll == roll)
        {
            printf("%d is in this list. Memory address is %x\n", roll, current_node);
            flg = 1;
            break;
        }
        else
            current_node = current_node->next;
    }
    if(flg = 0)
        printf("Roll is not found\n");

}

void print()
{
    node *current_node = root;
    while(current_node != NULL)
    {
        printf("%d\n", current_node->roll);
        current_node = current_node->next;
    }
}

int main()
{
    printf("All elements\n");
    insert_at_last(1);
    insert_at_last(1);
    insert_at_last(2);
    insert_at_last(3);
    print();
    printf("After deleting\n");
    delete_node(1);
    print();
    printf("Insert at first\n");
    insert_at_first(0);
    print();
    printf("Insert a value 4 after 2\n");
    insert_after_key(2, 4);
    print();
    printf("searching 3 is in the list or not\n");
    search_roll(3);

    return 0;
}
