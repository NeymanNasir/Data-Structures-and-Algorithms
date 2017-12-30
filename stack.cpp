/*#include<iostream>
#include<cstdio>
using namespace std;

#define stackSize 10
int mystack[stackSize], top = -1;

void push(int value)
{
    if(top >= stackSize-1)
        printf("Stack is full!\n");
    else
    {
        printf("PUSH: %d\n", value);
        mystack[++top] = value;
    }
}

void peek()
{
    if(top < 0)
        printf("Stack underflow!\n");
    else
        printf("%d\n", mystack[top]);
}

void pop()
{
    if(top < 0)
        printf("Stack underflow!\n");
    else
    {
        printf("Popped %d, from stack\n", mystack[top]);
        top--;
    }
}

void displayStack()
{
    printf("\nPrint the full stack from TOP to BOTTOM: \n");
    for(int i = top; i >= 0; i--)
        printf("%d\n", mystack[i]);
}

int main()
{
    push(5);
    push(90);
    push(12);
    displayStack();

    pop();
    displayStack();

    printf("\nTop value of this stack: ");
    peek();

    return 0;
}*/
//using stl stack
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

stack<int> mystack;

int main()
{
    for(int i = 0; i < 11; i++)
    {
        mystack.push(i+10);
    }

    cout <<"Stack size "<<mystack.size()<< endl;
    cout <<"Top element "<<mystack.top()<< endl;
    if(!mystack.empty()) mystack.pop();
    cout <<"top element after a pop "<< mystack.top()<< endl;

    return 0;
}
