#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n,k;
	cin>>n>>k;
	ll a[n]{};
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	multiset<ll> s1;
    multiset<ll, greater<ll>> s2;
    for(ll i=0;i<k;i++)
    {
        s1.insert(a[i]);
    }
    for(ll i=0;i<k-k/2;i++)
    {
        s2.insert(*s1.begin());
        s1.erase(s1.begin());
    }
    ll ans=0,ref=*s2.begin();
    for(auto it=s1.begin();it!=s1.end();it++)
    {
        ans+=abs(ref-*it);
    }
    for(auto it=s2.begin();it!=s2.end();it++)
    {
        ans+=abs(ref-*it);
    }
    cout<<ans<<" ";
    ll toremove = 0;
    for(ll i=k;i<n;i++)
    {
        if(a[toremove] <= *s2.begin())
        {
            s2.erase(s2.lower_bound(a[toremove]));
        }
        else
        {
            s1.erase(s1.lower_bound(a[toremove]));
            if(s2.size()-s1.size()>1)
            {
                s1.insert(*s2.begin());
                s2.erase(s2.begin());
            }
        }
        if(s2.size() && a[i] <= *s2.begin())
        {
            s2.insert(a[i]);
            if(s2.size()-s1.size()>1)
            {
                s1.insert(*s2.begin());
                s2.erase(s2.begin());
            }
        }
        else
        {
            s1.insert(a[i]);
            if(s1.size()!=s2.size())
            {
                s2.insert(*s1.begin());
                s1.erase(s1.begin());
            }
        }
        toremove++;
        ll ans=0,ref=*s2.begin();
        for(auto it=s1.begin();it!=s1.end();it++)
        {
            ans+=abs(ref-*it);
        }
        for(auto it=s2.begin();it!=s2.end();it++)
        {
            ans+=abs(ref-*it);
        }
        cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}