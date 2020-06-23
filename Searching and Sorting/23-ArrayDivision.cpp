#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool possible(ll a[], ll n, ll k, ll mid)
{
    ll sum=0;
    ll partition=0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]>mid) return false;
        
        sum+=a[i];
        if(sum>mid)
        {
            partition++;
            sum=a[i];
        }
        if(partition>k)
        {
            return false;
        }
    }
    partition++;
    if(partition>k)
    {
        return false;
    }
    return true;
}

int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n]{};
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    ll start=1;
    ll end = 1e18;
    ll ans=0;
    while(start <= end)
    {
        ll mid = end - (end-start)/2;
        if(possible(a, n, k, mid))
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