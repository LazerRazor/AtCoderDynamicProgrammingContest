#include<bits/stdc++.h>
#define int long long 
using namespace std;

int32_t main()
{
    int n, w; cin >> n >> w;

    int items[n+1][2], dp[n+1][100001];

    for(int i = 1; i <= n; i++) 
    {
        cin >> items[i][0] >> items[i][1];
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= 100000; j++)
        {
            dp[i][j] = w + 1;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        dp[i-1][0] = 0;

        for(int j = 1; j <= 100000; j++)
        {
            dp[i][j] = dp[i-1][j];

            if(j >= items[i][1] && dp[i-1][j - items[i][1]] + items[i][0] <= w)
            {
                dp[i][j] = min(dp[i][j], items[i][0] + dp[i-1][j - items[i][1]]);
            }
        }
    }

    int answer = 0;

    for(int i = 0; i <= 100000; i++)
    {
        if(dp[n][i] <= w) answer = i;
    }

    cout << answer << "\n";
}