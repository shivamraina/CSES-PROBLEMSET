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
    // Sliding window
    ll curr=0, ans=0;
    ll index=-1;
    for(ll i=0;i<n;i++)
    {
        curr+=a[i];
        if(curr==x)
        {
            ans++;
        }
        if(curr > x)
        {
            index = i;
            break;
        }
    }
    if(index!=-1 && index!=n-1)
    {
        ll start = 0;
        ll end = index+1;
        while(end<n)
        {
            while(curr>x && start<n)
            {
                curr-=a[start];
                start++;
            }
            while(curr<x && end<n)
            {
                curr+=a[end];
                end++;
            }
            if(curr==x)
            {
                ans++;
                if(end<n)
                {
                    curr+=a[end];
                    end++;
                }
                else
                {
                    break;
                }
            }
        }
        while(curr>x && start<n)
        {
            curr-=a[start];
            start++;
        }
        if(curr==x)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}