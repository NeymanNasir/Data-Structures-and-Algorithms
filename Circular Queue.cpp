//According to Bappy nur vai
#include<iostream>
#include<cstdio>
using namespace std;

const int size = 5;
int arr[size];
int front = 1;
int rear = 1;

void enque(int value)
{
    int next_rear = (rear+1) % size;
    cout <<"next_rear = " << next_rear << endl;
    if(next_rear == front)
        cout <<"Queue is full." << endl;
    else
    {
        arr[rear] = value;
        cout <<"rear = "<<rear << endl;
        rear = next_rear;
    }
}

void deque()
{
    if(front == rear)
        cout << "Queue is empty!"<<endl;
    else
    {
        front = (front+1)%size;
        cout<<"front = "<< front << endl;
    }
}

void print()
{
    cout <<"\nCurrent Queue: ";
    for(int i = front; i != rear; i = (i+1)%size)
        cout << arr[i] <<" ";

    cout << endl<<endl;;
}
int main()
{
    enque(3);
    print();
    enque(4);
    print();
    enque(7);
    print();
    enque(2);
    print();
    enque(5);
    print();

    cout <<"dequeue " <<endl;
    deque();
    print();
    enque(3);
    print();

    return 0;
}
