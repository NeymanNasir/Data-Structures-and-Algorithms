#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define queuesize 100

int myQueue[queuesize], head = 0, tail = -1;

void enqueue(int value)
{
    if(tail == queuesize)
        printf("Queue is full. Cannot push any data!\n");
    else
        myQueue[++tail] = value;
}

void dequeue()
{
    if(head == queuesize)
        printf("Queue is Empty!\n");
    else
        printf("Dequeue: %d\n", myQueue[head++]);
}

void display()
{
    for(int i = head; i <= tail; i++)
        printf("%d\n", myQueue[i]);

}

int main()
{
    for(int i = 1; i <= 10; i++)
        enqueue(i*10);

    printf("Full Queue is: \n");
    display();
    puts("");

    dequeue();
    dequeue();

    //Display the updated queue
    printf("\nUpdated Queue is: \n");
    display();
    puts("");

    //Enqueue another value
    printf("Enqueue another value 540\n");
    enqueue(540);

    printf("\nUpdated Queue is: \n");
    display();
    puts("");


    return 0;
}

//using stl queue
/*#include<queue>
using namespace std;

int main()
{
    queue<int> myQueue;

    myQueue.push(30); //push
    myQueue.push(50);

    printf("%d\n", myQueue.front())//return front element, but doesn't pop

    if(!myQueue.empty())
        myQueue.pop(); //pop but doesn't return

    myQueue.size() //size of the queue
}*/
