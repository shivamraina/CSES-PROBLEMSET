#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cout<< ((i*i)*(i*i-1)/2) - (4*(i-1)*(i-2))<<endl;
    }
 
    return 0;
}