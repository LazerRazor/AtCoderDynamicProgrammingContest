#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int32_t main()
{
    int n, m; cin >> n >> m;

    char grid[n+1][m+1];
    int dp[n+1][m+1];

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }

    dp[0][1] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(grid[i][j] == '#') dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][m] << "\n";
}