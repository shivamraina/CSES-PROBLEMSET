#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    string s;
    cin>>s;
    
    ll ans=0;
    ll c=1;
    char prev=s[0];
    for(ll i=1;i<s.length();i++)
    {
        if(s[i]==prev){
            c++;
        } else {
            ans = max(ans, c);
            c=1;
            prev=s[i];
        }
    }
    ans = max(ans, c);
    cout<<ans;
    
    return 0;
}