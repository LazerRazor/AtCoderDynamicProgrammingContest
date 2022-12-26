#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3000;
int a[N], dp[N][N], n;

int f(int i, int j)
{
    if(i > j) return 0;
    
    if(i == j) return a[i];

    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = max(a[i] + min(-a[i + 1] + f(i + 2, j), -a[j] + f(i + 1, j - 1)), 
                          a[j] + min(-a[i] + f(i + 1, j - 1), -a[j - 1] + f(i, j - 2))); 
}

int32_t main()
{
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    cout << f(0, n - 1) << "\n";
}