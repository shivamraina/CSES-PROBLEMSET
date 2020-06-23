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
    stack<ll> s;
    ll ans[n]{};
    for(ll i=0;i<n;i++)
    {
        if(s.empty())
        {
            s.push(i);
            ans[i]=0;
        }
        else
        {
            while(!s.empty() && a[s.top()]>=a[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                ans[i]=0;
                s.push(i);
            }
            else
            {
                ans[i] = s.top()+1;
                s.push(i);
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}