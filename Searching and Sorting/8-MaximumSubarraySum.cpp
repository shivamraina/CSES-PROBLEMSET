#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ll n;
    cin>>n;
    ll a[n]{};
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll c=0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            c++;
        }
    }
    if(c==n)
    {
        cout<<*max_element(a, a+n)<<endl;
        return 0;
    }
    
    ll ans=0;
    ll curr=0;
    
    for(ll i=0;i<n;i++)
    {
        curr+=a[i];
        if(curr<0)
        {
            curr=0;
        }
        ans = max(ans, curr);
    }
    cout<<ans<<endl;
    
    return 0;
}