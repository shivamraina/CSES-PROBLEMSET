#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n]{};
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    multiset<ll> s;
    for(ll i=0;i<k;i++)
    {
        s.insert(a[i]);
    }
    ll ans[n-k+1];
    ll idx=0;
    ll inc = (k+1)/2;
    ans[idx] = *(next(s.begin(), inc-1));
    ll last=0;
    idx++;
    for(ll i=k;i<n;i++)
    {
        s.erase(s.lower_bound(a[last]));
        last++;
        s.insert(a[i]);
        ans[idx] = *(next(s.begin(), inc-1));
        idx++;
    }
    for(ll i=0;i<n-k+1;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}