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
    
    sort(a, a+n);
    ll ans=0;
    ll ref = a[n/2];
    for(ll i=0;i<n;i++)
    {
        ans+=(abs(ref-a[i]));
    }
    cout<<ans<<endl;
    
    return 0;
}