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
    ll ans=0;   
    for(ll i=1;i<n;i++){
        if(a[i] < a[i-1])
        {
            ans += a[i-1]-a[i];
            a[i] += a[i-1]-a[i];
        }
    }
    cout<<ans;
    
    return 0;
}