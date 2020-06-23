#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    
    ll ans=0;
    ll a[n]{};
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        ans+=a[i];
    }
    sort(a, a+n);
    cout<<max(ans, 2*a[n-1])<<endl;
    return 0;
}