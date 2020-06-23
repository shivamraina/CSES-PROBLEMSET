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

    sort(a, a+n);

    ll i=0,j=n-1;

    while(i<j)
    {
        if(a[i].first+a[j].first == x)
        {
            cout<<a[i].second<<" "<<a[j].second<<endl;
            return 0;
        }
        if(a[i].first+a[j].first<x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    
    cout<<"IMPOSSIBLE\n";
    return 0;
}