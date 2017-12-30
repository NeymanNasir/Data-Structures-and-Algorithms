//According to  Geek for Geeks
#include<iostream>
#include<cstdio>
#include<cstdlib>
#define NULL 0
using namespace std;

//A linked list(LL) node to store a queue entry
struct QNode
{
    int key;
    QNode *next;
};
//The queue, front stores the front node of LL and back stores the last node of LL
struct Queue
{
    QNode *front;
    QNode *back;
};
//A utility function to create a new linked list node.
QNode *get_newNode(int K)
{
    QNode *temp = new QNode();
    temp->key = K;
    temp->next = NULL;

    return temp;
};
//A utility function to create an empty queue
Queue *create_emptyQueue()
{
    Queue *Q = new Queue();
    Q->front = NULL;
    Q->back = NULL;

    return Q;
}
//The function to add a key K to Q
void enQueue(Queue *Q, int K)
{
    //create a new LL node
    QNode *temp = get_newNode(K);

    //If queue is empty, then new node is front and back both
    if(Q->back == NULL)
    {
        Q->front = temp;
        Q->back = temp;
    }
    else
    {
        //Add the new node at the end of queue and change back
        Q->back->next = temp;
        Q->back = temp;
    }
}

//Function to remove a key from given queue Q
void deQueue(Queue *Q)
{
    //if queue is empty, return NULL.
    if(Q->front == NULL)
    {
        printf("Queue is already empty!\n");
    }
    else
    {
    //store previous front and move front one node ahead
    QNode *temp = Q->front;
    Q->front = Q->front->next;

    //If front becomes NULL, then change back also as NULL
    if(Q->front == NULL)
        Q->back = NULL;

    printf("Dequeued element is %d.\n", temp->key);
    delete(temp);
    }
}

void display_Queue(Queue *Q)
{
    printf("\nFull Queue is given below: \n");
    QNode *temp = Q->front;
    while(temp != NULL)
    {
        printf("%d\n", temp->key);
        temp = temp->next;
    }
}
int main()
{
    Queue *Q = create_emptyQueue();
    enQueue(Q, 10);
    enQueue(Q, 20);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    enQueue(Q, 30);
    enQueue(Q, 40);
    enQueue(Q, 50);
    deQueue(Q);
    display_Queue(Q);
    deQueue(Q);
    enQueue(Q, 60);
    enQueue(Q, 70);
    enQueue(Q, 80);
    enQueue(Q, 90);
    enQueue(Q, 100);
    display_Queue(Q);



    return 0;
}
