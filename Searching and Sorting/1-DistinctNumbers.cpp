#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin>>n;
	ll a[n]{};
	map<ll,ll> m;
    for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	cout<<m.size()<<endl;

	return 0;
}