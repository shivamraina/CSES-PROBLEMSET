#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin>>n;
 
    ll sum = n*(n+1)/2;
    if(sum & 1 || (n%4!=0 && n%4!=3)){
        cout<<"NO\n";
        return 0;
    }
 
    if(n%4==0){
        cout<<"YES\n";
        cout<<n/2<<endl;
        for(ll i=1;i<=n/2;i+=2)
        {
            cout<<i<<" "<<n+1-i<<" ";
        }
        cout<<endl<<n/2<<endl;
        for(ll i=2;i<=n/2;i+=2)
        {
            cout<<i<<" "<<n+1-i<<" ";
        }
    }
 
    else {
        cout<<"YES\n";
        cout<<n/2+1<<endl;
        cout<<1<<" "<<2<<" ";
        for(ll i=1;i<=(n-3)/2;i+=2)
        {
            cout<<3+i<<" "<<n+1-i<<" ";
        }
        cout<<endl<<n - (n/2+1) <<endl;
        cout<<3<<" ";
        for(ll i=2;i<=(n-3)/2;i+=2)
        {
            cout<<3+i<<" "<<n+1-i<<" ";
        }
    }
 
 
    return 0;
}