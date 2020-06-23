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
    map<ll,ll> umap;
    ll ans=0;
    ll curr=0;
    ll lastRejected=0;
    for(ll i=0;i<n;i++)
    {
        if(umap.find(a[i])==umap.end())
        {
            umap[a[i]] = i;
            curr++;
            ans = max(ans, curr);
        }
        else if(umap[a[i]] < lastRejected)
        {
            umap[a[i]] = i;
            curr++;
            ans = max(ans, curr);
        }
        else
        {
            curr = i-umap[a[i]];
            lastRejected = umap[a[i]];
            umap[a[i]] = i;
        }
    }
    
    cout<<ans<<"\n";
    return 0;
}