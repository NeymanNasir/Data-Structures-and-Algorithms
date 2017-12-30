#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

string addition(string s1, string s2)
{
    string ans;

    if(s2.size()>s1.size())
        swap(s1, s2);

    int i, sum = 0, carry = 0, l = s1.size();

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    //printf("%d\n", l);

    for(i = 0; i <l; i++) s2 += "0";

    for(i = 0; i < l; i++)
    {
        sum = (s1[i]-'0') + (s2[i]-'0') + carry;
        ans += (sum % 10) + '0'; //in c++ we can concanate
        //cout<<ans<<endl;        //one string to other by '+' operator
        carry = sum / 10;
    }

    if(carry>0) ans += carry%10 + '0';

    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{
    string a, b, ans;

    cin >>a >>b;

    ans = addition(a, b);
    cout<< ans<< endl;

    return 0;
}
