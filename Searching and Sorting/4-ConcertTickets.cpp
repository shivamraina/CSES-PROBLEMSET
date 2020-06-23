#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ll n, m;
    cin>>n>>m;
 
    multiset<ll> price;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        price.insert(x);
    }

    ll ans[m]{};
    memset(ans, -1, sizeof(ans));
 
    for(ll i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        auto it = price.upper_bound(x);
        if(it == price.begin())
        {
            ans[i]=-1;
        }
        else
        {
            it--;
            ans[i] = *(it);
            price.erase(it);
        }
    }
 
    for(ll i=0;i<m;i++)
    {
        cout<<ans[i]<<endl;
    }
 
    return 0;
}