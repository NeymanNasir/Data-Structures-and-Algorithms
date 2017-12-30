///according to hellohasan blog
#include<iostream>
#include<cstdio>
#include<limits.h>
using namespace std;
#define NULL 0

struct node
{
    int data;
    node* left = NULL;
    node* right = NULL;
};
node* root = NULL;

void insert_node(int value)
{
    node *temp_node;
    node *current_node = NULL;
    node *parent_node = NULL;

    temp_node = new node();
    temp_node->data = value;

    if(root == NULL)
        root = temp_node;
    else
    {
        current_node = root;
        parent_node = NULL;

        while(1)
        {
            parent_node = current_node;

            if(value <= parent_node->data)
            {
                current_node = current_node->left;
                if(current_node == NULL)
                {
                    parent_node->left = temp_node;
                    return;
                }
            }
            else
            {
                current_node = current_node->right;
                if(current_node == NULL)
                {
                    parent_node->right = temp_node;
                    return;
                }
            }
        }
    }

}

void search(int value)
{
    node* current_node = root;
    int flg = 0;

    while(1)
    {
        if(value == current_node->data)
        {
            flg = 1;
            break;
        }
        else if(value <= current_node->data)
            current_node = current_node->left;
        else
            current_node = current_node->right;

        if(current_node == NULL)
            break;
    }

    if(flg == 1)
        printf("\n%d is found on Tree.\n\n", current_node->data);
    else
        printf("\n%d is not found on Tree.\n\n", value);
}

void pre_order_print(node* root)
{
    if(root == NULL)
        return;

    printf("%d ", root->data);

    pre_order_print(root->left);
    pre_order_print(root->right);
}

void in_order_print(node* root) //sorting lower to higher
{
    if(root == NULL)
        return;

    in_order_print(root->left);

    printf("%d ", root->data);

    in_order_print(root->right);
}

void post_order_print(node* root)
{
    if(root == NULL)
        return;

    post_order_print(root->left);
    post_order_print(root->right);

    printf("%d ", root->data);
}

node* find_max(node* root)
{
    if(root->right == NULL)
        return root;

    return find_max(root->right);
}

node* find_min(node* root)
{
    if(root->left == NULL)
        return root;

    return find_min(root->left);
}

node *delete_node(node *current_node, int value)
{
    if(current_node == NULL)
        return NULL;
    else if(value < current_node->data)
        current_node->left = delete_node(current_node->left, value);
    else if(value > current_node->data)
        current_node->right = delete_node(current_node->right, value);
    else
    {
        //node has no child
        if(current_node->left == NULL && current_node->right == NULL)
            current_node = NULL;
        else if(current_node->left == NULL) //node has only right child
            current_node = current_node->right;
        else if(current_node->right == NULL) //node has only left child
            current_node = current_node->left;
        else //node has two children
        {
            node* temp = find_min(current_node->right);
            current_node->data = temp->data;
            current_node->right = delete_node(current_node->right, temp->data);
        }
    }

    return current_node;

}

int is_BST(node* root, int temp) //By in Order traversal
{
    if(root == NULL) //Base case
        return 1;

    if(!is_BST(root->left, temp))
        return 0;

    if(root->data < temp)
        return 0;

    temp = root->data;

    return is_BST(root->right, temp);
}

int main()
{
    insert_node(45);
    insert_node(54);
    insert_node(40);
    insert_node(49);
    insert_node(38);
    insert_node(70);
    insert_node(30);
    insert_node(39);
    insert_node(41);
    insert_node(45);
    insert_node(44);

    printf("\nPre-Order Tree printing:\n");
    pre_order_print(root);

    printf("\n\nIn-order Tree printing:\n");
    in_order_print(root);

    printf("\n\nPost-order Tree printing:\n");
    post_order_print(root);
    puts("");

    search(49);

    node* max_node = find_max(root);
    if(max_node != NULL)
        printf("\nMaximum value of the Tree: %d\n", max_node->data);
    else
        printf("\n\nTree is empty!\n");

    node* min_node = find_min(root);
    if(min_node != NULL)
        printf("\nMinimum value of the Tree: %d\n", min_node->data);
    else
        printf("\n\nTree is empty!\n");

    //Delete 30 from BST
    root = delete_node(root, 30);
    printf("\n\nIn-order Tree printing:\n");
    in_order_print(root);
    puts("");

    int temp = INT_MIN;
    printf("\nIs it BST???\n");
    if(is_BST(root, temp))
        printf("\nIn-order traversal Approach:\nYes, it is BST!\n");
    else
        printf("\nIn-order traversal Approach:\nNO, it is not BST!\n");

    return 0;
}
