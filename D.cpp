#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int n, w; cin >> n >> w;

    int items[n+1][2], dp[n+1][w+1]; 

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++)
    {
        cin >> items[i][0] >> items[i][1];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            if(j < items[i][0]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(items[i][1] + dp[i-1][j - items[i][0]], dp[i-1][j]);
        }
    }

    cout << dp[n][w] << "\n"; 
}