#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,x;
    cin>>n>>x;
    pair<ll,ll> a[n]{};
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a,a+n);
    ll flag=0;
    for(ll i=0;i<n-1;i++)
    {
        ll start = i+1;
        ll end = n-1;
        while(start<end)
        {
            if(a[start].first+a[end].first+a[i].first==x)
            {
                flag=1;
                cout<<a[i].second<<" "<<a[start].second<<" "<<a[end].second<<endl;
                break;
            }
            if(a[start].first+a[end].first < x-a[i].first)
            {
                start++;
            }
            else
            {
                end--;
            }
            
        }
        if(flag)
        {
            break;
        }
    }
    if(!flag)
    {
        cout<<"IMPOSSIBLE\n";
    }
    
    return 0;
}