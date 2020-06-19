#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans=0;
ll n = 7;
bool visited[7][7]{};

void solve(string s, ll r, ll c, ll idx)
{
    if(r==6 && c==0)
    {
        if(idx == 48) ans++;
        return;
    }

    if (((r + 1 == n || (visited[r - 1][c] && visited[r + 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c + 1 == n || (visited[r][c - 1] && visited[r][c + 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]) ||
        ((r == 0 || (visited[r + 1][c] && visited[r - 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c == 0 || (visited[r][c + 1] && visited[r][c - 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]))
        return;

    visited[r][c] = true;

    if(s[idx]!='?')
    {
        if(s[idx]=='D' && r+1<7 && !visited[r+1][c])
        {
            solve(s, r+1, c, idx+1);
        }
        else if(s[idx]=='R' && c+1<7 && !visited[r][c+1])
        {
            solve(s, r, c+1, idx+1);
        }
        else if(s[idx]=='L' && c>0 && !visited[r][c-1])
        {
            solve(s, r, c-1, idx+1);
        }
        else if(s[idx]=='U' && r>0 && !visited[r-1][c])
        {
            solve(s, r-1, c, idx+1);
        }
    }

    else
    {
        if(r+1<7 && !visited[r+1][c])
        {
            solve(s, r+1, c, idx+1);
        }
        if(c+1<7 && !visited[r][c+1])
        {
            solve(s, r, c+1, idx+1);
        }
        if(c>0 && !visited[r][c-1])
        {
            solve(s, r, c-1, idx+1);
        }
        if(r>0 && !visited[r-1][c])
        {
            solve(s, r-1, c, idx+1);
        }
    }

    visited[r][c] = false;
}

int main()
{
    string s;
    cin>>s;

    solve(s, 0, 0, 0);
    cout<<ans<<endl;
    return 0;
}