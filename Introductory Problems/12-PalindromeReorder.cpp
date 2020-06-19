#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(pair<char,ll> a, pair<char,ll> b)
{
    return a.second>b.second;
}

int main()
{
    string s;
    cin>>s;
    
    map<char, ll> m;
    vector<pair<char, ll>> v;
    for(ll i=0;i<s.length(); i++)
    {
        m[s[i]]++;
    }
    for(auto x:m)
    {
        v.push_back({x.first,x.second});
    }
    sort(v.begin(), v.end(), comp);
    
    string ans;
    string rev;
    ll c=0;
    for(ll i=0;i<v.size();i++)
    {
        if(v[i].second%2!=0)
        {
            c++;
        }
    }
    if(c>1)
    {
        cout<<"NO SOLUTION\n";
        return 0;
    }
    ll index=-1;
    for(ll i=0;i<v.size();i++)
    {
        if(v[i].second%2==0)
        {
            for(ll j=0;j<v[i].second/2;j++)
            {
                ans+=v[i].first;
                rev+=v[i].first;
            }
            v[i].second=0;
        }
        else
        {
            for(ll j=0;j<v[i].second/2;j++)
            {
                ans+=v[i].first;
                rev+=v[i].first;
            }
            v[i].second=1;
            index = i;
        }
    }
    
    if(index!=-1)
        ans+=v[index].first;
    reverse(rev.begin(),rev.end());
    ans+=rev;
    cout<<ans<<endl;
    
    return 0;
}