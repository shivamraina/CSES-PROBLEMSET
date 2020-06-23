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
    ll curr=0;
    ll mod[n]{};
    for(ll i=0;i<n;i++)
    {
        curr+=a[i];
        mod[(curr%n+n)%n]++;
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        if(mod[i]>1)
        {
            ans+=(mod[i]*(mod[i]-1))/2;
        }
    }
    ans+=mod[0];
    cout<<ans<<endl;
    return 0;
}