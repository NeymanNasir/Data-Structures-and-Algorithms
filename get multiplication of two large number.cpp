//Yes I implement this
//multiplication for all positive integer
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

string addition(string s1, string s2)
{
    //cout<<s1<<endl<<s2<<endl;
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

string multiplication(string s1, string s2)
{
    string muli, mulj = "0";
    if(s2.size()>s1.size())
        swap(s1, s2);

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int i, j, carry, l1 = s1.size(), l2 = s2.size(), x = 0, y = 0, mul;

    for(i = 0; i < l2; i++){
        carry = 0;
        mul = 0;
        muli.clear();

        for(j = 0; j < l1; j++){
            mul = (s1[j]-'0') * (s2[i]-'0') + carry;     //here we multiply a by every integer of b;
            muli += (mul%10) + '0';                       //here we get our result of every multiplication
            carry = ((s1[j]-'0') * (s2[i]-'0') + carry) / 10;
        }
        if(carry>0) muli += carry%10 + '0';

        x++;
        reverse(muli.begin(), muli.end());
        for(y = 0; y < x-1; y++)
            muli += "0";


        mulj = addition(muli, mulj);
        //cout<<mulj<<endl;
    }

    return mulj;
}
int main()
{
    string a, b, ans;

    cin >>a >>b;

    ans = multiplication(a, b);
    cout<< ans<< endl;

    return 0;
}
