#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare(pair<ll,ll> a, pair<ll,ll> b)
{
    return a.first < b.first;
}

int main()
{
    ll n;
    cin>>n;
    
    pair<ll,ll> a[n]{};
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].first;
        cin>>a[i].second;
    }
    
    sort(a, a+n, compare);
    ll ans=0;
    ll curr=0;
    for(ll i=0;i<n;i++)
    {
        curr+=a[i].first;
        ans += (a[i].second - curr);
    }
    cout<<ans<<endl;
    return 0;
}