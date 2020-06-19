#include <bits/stdc++.h>
using namespace std;

int ans=0;
const int n = 7;
bool visited[7][7]{};
int arr[49]{};

void solve(int r, int c, int idx)
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

    if(arr[idx]!=-1)
    {
        switch (arr[idx])
        {
            case 0:
                if(r-1>=0 && !visited[r-1][c])
                {
                    solve(r-1, c, idx+1);
                }
                break;

            case 1:
                if(c-1>=0 && !visited[r][c-1])
                {
                    solve(r, c-1, idx+1);
                }
                break;

            case 2:
                if(r+1<7 && !visited[r+1][c])
                {
                    solve(r+1, c, idx+1);
                }
                break;
            
            case 3:
                if(c+1<7 && !visited[r][c+1])
                {
                    solve(r, c+1, idx+1);
                }
                break;
        }
        visited[r][c]=false;
        return;
    }

    else
    {
        if(r+1<7 && !visited[r+1][c])
        {
            solve(r+1, c, idx+1);
        }
        if(c+1<7 && !visited[r][c+1])
        {
            solve(r, c+1, idx+1);
        }
        if(c>0 && !visited[r][c-1])
        {
            solve(r, c-1, idx+1);
        }
        if(r>0 && !visited[r-1][c])
        {
            solve(r-1, c, idx+1);
        }
    }

    visited[r][c] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '?')
            arr[i] = -1;
        else if (s[i] == 'U')
            arr[i] = 0;
        else if (s[i] == 'L')
            arr[i] = 1;
        else if (s[i] == 'D')
            arr[i] = 2;
        else if (s[i] == 'R')
            arr[i] = 3;
    }
    
    solve(0, 0, 0);
    cout<<ans<<endl;
    
    return 0;
}
