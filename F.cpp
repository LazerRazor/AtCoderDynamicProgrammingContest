#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s, t; cin >> s >> t;

    int dp[s.size() + 1][t.size() + 1];

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= s.size(); i++)
    {
        for(int j = 1; j <= t.size(); j++)
        {
            if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int x = s.size(), y = t.size();

    string answer = "";

    while(x > 0 && y > 0)
    {
        if(dp[x][y] > dp[x - 1][y] && dp[x][y] > dp[x][y - 1]) answer += s[x - 1], x--, y--;
        else if(dp[x - 1][y] == dp[x][y]) x--;
        else if(dp[x][y - 1] == dp[x][y]) y--;
    }

    reverse(answer.begin(), answer.end());

    cout << answer << "\n";
}