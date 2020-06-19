#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ll n;
    cin>>n;
    
    ll sum1 = n*(n+1)/2;
    ll sum2=0;
    for(ll i=0;i<n-1;i++)
    {
        ll x;
        cin>>x;
        sum2+=x;
    }
    
    cout<<sum1-sum2;
    return 0;
}