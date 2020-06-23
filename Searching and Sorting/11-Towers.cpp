#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    
    multiset<ll> tops;
    
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        if(tops.size()==0)
        {
            tops.insert(x);
        }
        else
        {
            auto it = tops.upper_bound(x);
            if(it == tops.end())
            {
                tops.insert(x);
            }
            else
            {
                tops.erase(it);
                tops.insert(x);
            }
        }
    }
    cout<<tops.size()<<endl;
    return 0;
}