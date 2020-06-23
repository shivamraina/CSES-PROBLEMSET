#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class customer
{
public:
    ll start,end,idx;
};

bool compare(pair<ll,pair<ll,ll>> a, pair<ll,pair<ll,ll>> b)
{
    if(a.first != b.first)
        return a.first<b.first;
    if(a.second.first != b.second.first)
        return a.second.first<b.second.first;
    return a.second.second>b.second.second;
}

int main()
{
    ll n;
    cin>>n;
    
    customer arr[n]{};
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i].start;
        cin>>arr[i].end;
        arr[i].idx = i;
    }
    
    vector<pair<ll,pair<ll,ll>>> v;
    for(ll i=0;i<n;i++)
    {
        v.push_back({arr[i].start, {0, arr[i].idx}});
        v.push_back({arr[i].end, {1, arr[i].idx}});
    }
    
    sort(v.begin(), v.end(), compare);
    
    ll ans=0,curr=0;
    vector<pair<ll,ll>> finalans;
    multiset<ll> freed;
    
    map<ll, ll> m;
    ll counter=1;
    
    for(ll i=0;i<v.size();i++)
    {
        if(v[i].second.first==0)
        {
            curr++;
            ans = max(ans, curr);
            if(!freed.empty())
            {
                finalans.push_back({v[i].second.second, *freed.begin()});
                freed.erase(freed.begin());
            }
            else
            {
                finalans.push_back({v[i].second.second, counter});  
                counter++;
            }
            pair<ll,ll> ref = *finalans.rbegin();
            ll indexInOriginal = ref.first;
            ll roomNumberAlloted = ref.second;
            m[indexInOriginal] = roomNumberAlloted;
        }
        else
        {
            curr--;
            // find the room allocated to corresponding ending time
            ll toremove = m[v[i].second.second];
            freed.insert(toremove);
        }
    }
    
    cout<<ans<<"\n";
    sort(finalans.begin(), finalans.end());
    for(auto x:finalans)
    {
        cout<<x.second<<" ";
    }
    cout<<endl;
    return 0;
}