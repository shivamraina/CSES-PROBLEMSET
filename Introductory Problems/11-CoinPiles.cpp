#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--)
    {
        ll a, b;
        cin>>a>>b;
        if(a==0 && b==0){
            cout<<"YES\n";
            continue;
        }
        if((a+b)%3==0 && a!=0 && b!=0 && 2*a>=b && 2*b>=a){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }

    return 0;
}