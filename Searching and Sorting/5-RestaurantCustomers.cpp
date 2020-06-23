#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ll n;
    cin>>n;
    
    pair<ll,ll> arr[n]{};
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    
    sort(arr, arr+n, [](pair<ll,ll> a, pair<ll,ll> b){
        return a.second<b.second;
    });
    
    vector<pair<ll,ll>> v;
    for(ll i=0;i<n;i++)
    {
        v.push_back({arr[i].first, 0});
        v.push_back({arr[i].second, 1});
    }
    
    sort(v.begin(), v.end());
    ll ans=0;
    ll curr=0;
    for(ll i=0;i<v.size();i++)
    {
        if(v[i].second==0)
        {
            curr++;
            ans = max(ans, curr);
        }
        else
        {
            curr--;
        }
    }
    cout<<ans<<endl;
    return 0;
}