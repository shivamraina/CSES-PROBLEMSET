#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool possible(ll a[], ll n, ll t, ll mid)
{
    ll produced=0;
    for(ll i=0;i<n;i++)
    {
        produced+=(mid/a[i]);
        if(produced>=t)
        {
            return true;
        }
    }
    return produced >= t;
}

int main()
{
    ll n,t;
    cin>> n >> t;
    ll a[n]{};
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a, a+n);
    ll start = 1;
    ll end = a[n-1]*t;
    ll ans=0;
    
    while(start <= end)
    {
        ll mid = end - (end-start)/2;
        if(possible(a, n, t, mid))
        {
            ans = mid;
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}