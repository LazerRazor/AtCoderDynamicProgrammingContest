#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;

    int a[n], dp[n];

    for(int i = 0; i < n; i++) cin >> a[i];

    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;

        for(int j = i - 1; j >= max(0, i - k); j--)
        {
            dp[i] = min(dp[i], abs(a[i] - a[j]) + dp[j]);
        }
    }

    cout << dp[n-1] << "\n";
}