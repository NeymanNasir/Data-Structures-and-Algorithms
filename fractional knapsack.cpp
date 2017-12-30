///from mahbub sir book
#include<algorithm>
#include<utility>
#include<vector>
#include<iostream>
using namespace std;

typedef pair<int, int> PII;
vector<PII> V;

bool cmp(PII A, PII B)
{
    return (A.second*B.first > A.first*B.second);///A.price*B.weight>B.price*A.weight
}

int main() ///fractional knapsack
{
    int n, w;
    cout << "Enter the number of goods store has and weights and prices of every goods\n";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int weight, price;
        cin >> weight >> price;
        V.push_back(PII(weight, price));
    }
    sort(V.begin(), V.end(), cmp);
    cout << "Enter the size of thief storage\n";
    cin >> w;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int steal = min(w, V[i].first);
        w -= steal;
        if(steal != V[i].first)
        {
            ans += (V[i].second * steal)/V[i].first;
        }
        else ans += V[i].second;
    }
    cout << "Maximum cost: "<< ans << endl;

    return 0;
}
