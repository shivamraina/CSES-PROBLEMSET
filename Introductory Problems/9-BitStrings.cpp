#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin>>n;
    
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans = ans*2 % (ll)(1e9+7);
    }
    cout<<ans;

    return 0;
}