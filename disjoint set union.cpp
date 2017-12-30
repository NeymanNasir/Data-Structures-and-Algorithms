///from sayefRehad
#include<iostream>
#include<cstdio>
using namespace std;
#define Size 100

int parent[Size];
int Rank[Size];

void InitializeSet(int n)
{
    for(int i = 0; i <= n; i++)
    {
        parent[i] = i;
        Rank[i] = 0;
    }
}

int find(int x) ///By using find We find representative of elements
{
    if(x != parent[x])
        return parent[x] = find(parent[x]); ///it's reduce depth for using path compression
    else
        return x;
}

void unionSet(int x, int y)
{
    int px = find(x);
    int py = find(y);

    if (px == py)
        return;

    if(Rank[px] < Rank[py])
        parent[px] = py;
    else if(Rank[px] > Rank[py])
        parent[py] = px;
    else  ///rank uses for only know, that which set contains more elements. so when two set ranks are same that time we change our rank value.
    {
        parent[py] = px;
        Rank[px]++;
    }
}

void printSet(int n)
{
    cout << "Find parent of every elements:\n";
    for(int i = 0; i <= n; i++)
        cout << "Parent of "<< i << " is " << parent[i]<< endl;
    cout << endl;

    cout << "Find representative of every elements:\n";
    for(int i = 0; i <= n; i++)
        cout << "representative of "<< i << " is " << find(i)<< endl;
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    InitializeSet(n);

    unionSet(0, 1);
    unionSet(4, 2);
    unionSet(3, 1);
    unionSet(0, 3);

    printSet(n);

    unionSet(0, 4);


    printSet(n);
    return 0;
}
