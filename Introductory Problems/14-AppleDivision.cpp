#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll diff=INT_MAX;

void solve(ll a[], ll sum1, ll sum2, ll idx, ll n)
{
    if(idx>=n)
    {
        diff = min(diff, abs(sum1-sum2));
        return;
    }
    solve(a, sum1+a[idx], sum2, idx+1, n);
    solve(a, sum1, sum2+a[idx], idx+1, n);
}

int main()
{
	ll n;
    cin>>n;
    ll a[n]{};
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    solve(a, 0, 0, 0, n);
    cout<<diff<<endl;
    return 0;
}