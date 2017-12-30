//according to mazed rupok vai
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> adj[100]; ///2D vector array

void BFS(int n, int src)
{
    queue<int> Q;
    Q.push(src);
    int visited[100] = {0};
    int level[100];
    int parent[100];
    visited[src] = 1;
    level[src] = 0;
    parent[src] = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!visited[v])
            {
                level[v] = level[u] + 1;
                parent[v] = u;
                visited[v] = 1;
                Q.push(v);
            }
        }
        Q.pop();
    }

    printf("\n");
    for(int i = 1; i <= n; i++)
    {
        printf("%d to %d distance %d\n", src, i, level[i]);
    }
    printf("\n");

    for(int i = n; i >= 1; i--)
    {
        printf("Path of %d: ", i);
        int j = i;
        printf("%d", j);
        while(parent[j])
        {
            printf(" -> %d", parent[j]);
            j = parent[j];
        }
        printf(".\n");
    }
}

int main()
{
    int x, y, N, E, i;
    cout << "Enter Nodes and Edges number: ";
    cin >> N >> E;

    cout << "Enter connected node's of every edges: "<< endl;
    for(i = 0; i < E; i++) //making adjacency list
    {
        cout <<"for Edge no " << i+1<< " : " ;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //while(1){
        BFS(N, 1);
    //}

    return 0;
}
