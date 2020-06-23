#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n,x;
	cin>>n>>x;
	ll a[n]{};
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	sort(a, a+n);
    ll ans=0;
    for(int i=0,j=n-1;i<j;)
    {
        while(i<j && a[i]+a[j]>x)
        {
            j--;
        }
        if(i>=j)
        {
            break;
        }
        ans++;
        i++;
        j--;
    }
    
	cout<<n-ans<<endl;

	return 0;
}