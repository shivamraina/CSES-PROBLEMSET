#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n,m,k;
	cin>>n>>m>>k;

	ll a[n]{};
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}

	ll b[m]{};
	for(ll i=0;i<m;i++)
	{
		cin>>b[i];
	}

	// code
	ll ans=0;
	sort(a, a+n);
	sort(b, b+m);
    
	bool visited[m]{};
    
	for(ll i=0;i<n;i++)
	{
		
		ll start = 0;
		ll end = m-1;
		while(start <= end)
		{
			ll mid = end - (end-start)/2;
			if(!visited[mid])
			{
				if(b[mid]>=a[i]-k && b[mid]<=a[i]+k && (mid==0 || b[mid-1]<a[i]-k || (visited[mid-1])))
				{
               		visited[mid] = true;
               		ans++;
                	break;
            	}
			}
			if(visited[mid])
			{
            	start=mid+1;
        	}
			else if(b[mid]<=a[i]+k && b[mid]>=a[i]-k)
			{
				end = mid-1;
			}
			else if(b[mid] < a[i]-k)
			{
				start = mid+1;
			}
			else
			{
				end = mid-1;
			}
		}
	}
    
	cout<<ans<<endl;

	return 0;
}