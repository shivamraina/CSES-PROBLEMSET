#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,q;
    cin>>n>>q;
    
    set<ll> lights = {0,n};
    multiset<ll> lengths = {n};
    
    for(ll i=0;i<q;i++)
    {
        ll a;
        cin>>a;
        
        set<ll>::iterator upper = lights.upper_bound(a);
        
        ll right, left;
        
        right = *upper;
        left = *prev(upper);
        
        lights.insert(a);
        lengths.erase(lengths.find(right - left));
        lengths.insert(right-a);
        lengths.insert(a-left);
        cout<<*lengths.rbegin()<<endl;
    }
    
    return 0;
}