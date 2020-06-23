#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,x;
    cin>>n>>x;
    ll a[n]{};
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll ans=0;
    // set
    map<ll,ll> m;
    ll curr=0;
    for(ll i=0;i<n;i++)
    {
        curr+=a[i];
        if(curr==x)
        {
            ans++;            
        }
        if(m.find(curr-x)!=m.end())
        {
            ans+=m[curr-x];
        }
        m[curr]++;
    }
    
    cout<<ans<<endl;
    return 0;
}