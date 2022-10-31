#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    vector<int>adj[n+1], dp(n+1,-1);

    for(int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    function<void(int)> dfs = [&](int u)
    {
        if(dp[u] != -1) return;

        dp[u] = 0;

        for(auto &v : adj[u])
        {
            dfs(v);
            dp[u] = max(dp[u], dp[v] + 1);
        }
    };

    for(int i = 1; i <= n; i++)
    {
        if(dp[i] == -1) dfs(i);
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}