#include<iostream>
#include<queue>
using  namespace std;

int main()
{
    priority_queue<int> mypq;
    int i, value;
    for(i = 0; i < 5; i++)
    {
        cin >> value;
        mypq.push(value);
    }
    cout << "First: " << mypq.top() << endl;
    mypq.pop();

    return 0;
}
