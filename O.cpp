#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 21;
const int MOD = 1e9 + 7;

int grid[MAXN][MAXN], dp[MAXN][(1 << MAXN)], n;

int f(int index, int mask)
{
    if(index == n)
    {
        return (mask == ((1 << n) - 1));
    }

    if(dp[index][mask] != -1) return dp[index][mask];

    int answer = 0;

    for(int i = 0; i < n; i++)
    {
        if(!(mask & (1 << i)) && grid[index][i] == 1)
        {
            answer += f(index + 1, mask|(1 << i));
            answer %= MOD;
        }
    }

    return dp[index][mask] = answer;
}

int32_t main()
{
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << f(0, 0) << "\n";
}