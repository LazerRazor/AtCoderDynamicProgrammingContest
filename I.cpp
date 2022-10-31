#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    long double a[n + 1], dp[n+1][n+1];

    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i-1][0] * (1 - a[i]);

        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j] * (1 - a[i]) + dp[i - 1][j - 1] * a[i];   
        }
    }

    long double answer = 0;

    for(int j = (n + 1) / 2; j <= n; j++) answer += dp[n][j];

    cout << setprecision(10) << answer << "\n";
}