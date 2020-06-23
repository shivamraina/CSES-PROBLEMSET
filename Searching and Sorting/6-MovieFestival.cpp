#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ll n;
    cin>>n;
    
    pair<ll,ll> a[n]{};
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    
    sort(a, a+n, [](pair<ll,ll> a, pair<ll,ll> b){
       return a.second<b.second; 
    });
    
    ll ans=1;
    ll i=0;
    ll j=1;
    
    while(j<n)
    {
        if(a[j].first >= a[i].second)
        {
            ans++;
            i=j;
        }
        j++;
    }
    cout<<ans<<endl;
    return 0;
}