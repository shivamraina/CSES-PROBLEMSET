#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

ll ans=0;
bool fr[1001][1001]{};
bool m[100][100]{};
vector<pair<ll,ll>> placed;

bool possible(ll row, ll col)
{
    if(!fr[row][col])
    {
        return 0;
    }
    for(ll i=0;i<row;i++)
    {
        if(m[i][col]==1)
            return false;
    }
    for(ll i=0;i<placed.size();i++)
    {
        if(col-row == placed[i].second-placed[i].first)
        {
            return false;
        }
    }
    for(ll i=0;i<placed.size();i++)
    {
        if(col+row == placed[i].second+placed[i].first)
        {
            return false;
        }
    }
    return true;
}

void solve(ll row, ll n)
{
    if(row>=n)
    {
        ans++;
        return;
    }
    
    for(ll j=0;j<n;j++)
    {
        if(possible(row,j))
        {
            m[row][j]=1;
            placed.push_back({row,j});
            solve(row+1, n);
            placed.pop_back();
            m[row][j]=0;
        }
    }
}

int main()
{
    fast;
    
    for(ll i=0;i<8;i++)
    {
        for(ll j=0;j<8;j++)
        {
            char x;
            cin>>x;
            if(x=='.')
            {
                fr[i][j]=1;
            }
            else
            {
                fr[i][j]=0;
            }
        }
    }
    solve(0, 8);
    cout<<ans;
    return 0;
}