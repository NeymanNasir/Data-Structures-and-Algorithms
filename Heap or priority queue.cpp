///according to bappi nur vai
///Max heap
#include<iostream>
using namespace std;

#define size 5
int ara[size+1];
int cnt; ///cnt = 0

///If parents in n
///Left child = n*2
///Right child = (n*2)+1
///Parent of any child = n/2
void Adjust_from_bottom(int bottom, int top)
{
    int item = ara[cnt];
    int i=cnt;
    while(i/2 >= 1)
    {
        if(ara[i/2]<item)
        {
            ara[i] = ara[i/2];

            i = i/2;
        }
        else
            break;

        ara[i] = item;///now i becomes i/2 when if statement works
    }
}

void Adjust_from_top(int st, int en)
{
    int item = ara[st];
    int i = st*2;
    while(i <= en)
    {
        if(i+1 <= en && ara[i+1] > ara[i])
        {
            i += 1;
        }
        else if(item >= ara[i])
            break;
        else
        {
            ara[i/2] = ara[i];
            i *= 2;
        }
    }
    ara[i/2] = item;
}
void Remove()
{
    if(cnt > 0)
    {
        ara[1] = ara[cnt];
        cnt--;
        Adjust_from_top(1, cnt);
    }
    else
        cout << "Heap is empty\n";
}

void insert_value(int value)
{
    if(cnt < size)
    {
        cnt++;
        ara[cnt] = value;
        Adjust_from_bottom(cnt, 1);
    }
    else
        cout << "Heap is full !"<< endl;
}

void print()
{
    cout << "Heap: ";
    for(int i = 1; i <= cnt; i++)
        cout << ara[i] << " ";
    cout << endl;
}

int main()
{
    insert_value(50);
    insert_value(90);
    insert_value(100);
    insert_value(500);
    insert_value(10);
    print();
    Remove();
    cout <<"After removing top element\n"<<endl;
    print();

    return 0;
}
