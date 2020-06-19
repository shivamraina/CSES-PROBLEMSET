#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ll n;
    cin>>n;
    
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    else if(n==2 ||n==3){
        cout<<"NO SOLUTION\n";
        return 0;
    }
    else if(n==4){
        cout<<"2 4 1 3\n";
        return 0;
    }
    vector<ll> v;
    for(ll i=1;i<=n;i+=2)
    {
        v.push_back(i);
    }
    for(ll i=2;i<=n;i+=2)
    {
        v.push_back(i);
    }
    for(auto x:v)
    {
        cout<<x<<" ";
    }
    
    return 0;
}