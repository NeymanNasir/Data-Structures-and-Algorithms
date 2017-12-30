///from shafayet vai blog
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define Size 10000

struct edge
{
    int u, v, w;
    bool operator < (const edge &p) const /// < operator overloading
    {
        return w < p.w;
    }
};

int par[Size];
vector<edge> E;
int find(int r) ///it's find out the representative of node
{
    if(r != par[r])
        return par[r] = find(par[r]);
    else
        return r;
}

int MST(int n)
{
    sort(E.begin(), E.end());
    for(int i = 1; i <= n; i++)
        par[i] = i;

    int cnt = 0, ans = 0;
    for(int i = 0; i < (int)E.size(); i++)
    {
        int u = find(E[i].u);
        int v = find(E[i].v);
        if(u != v) ///when there comes a circle then we get u=v. so we don't take it.
        {
            par[u] = v;
            cnt++;
            ans += E[i].w;

            if(cnt == n-1)
                break;
        }
    }
    return ans;
}
int main()
{
    int n, m; ///node and edge
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge get; ///define a variable named get as edge type
        get.u = u;
        get.v = v;
        get.w = w;
        E.push_back(get);
    }

    cout << "MST = "<< MST(n) << endl;

    return 0;
}
