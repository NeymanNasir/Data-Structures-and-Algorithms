//Biginteger subtraction implemented by me
//may have bug, I don't know.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

string subtraction(string s1, string s2)
{
    string ans;
    //bool flag = true;
    //string roots1 = s1;

    if(s2.size()>s1.size()){
        swap(s1, s2);
        }

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int i, sub = 0, l = s1.size(), carry = 0;

    for(i = 0; i < l; i++)
        s2 += "0";

    for(i = 0; i < l; i++)
    {
        if(s1[i]-'0' < (s2[i]-'0'+carry)) s1[i] = (s1[i]-'0')+10 + '0'; //if the element of b less then the element of a, then a would be a+10

        sub = (s1[i]-'0') - (s2[i]-'0'+carry);
        ans += sub + '0';
        //cout<<ans<<endl;
        carry = (s1[i]-'0')/10;
    }

    //string result = ans;
    reverse(ans.begin(), ans.end());

    //if((ans-'0') > (roots1-'0')) result += '-';
    //this code doesn't print sign'-', for negative answer
    //for implement this we may use Biginteger, will try later
    //reverse(result.begin(), result.end());

    return ans;
}
int main()
{
    string a, b, ans;

    cin >>a >>b;
    ans = subtraction(a, b);

    cout<<ans <<endl;

    return 0;
}
