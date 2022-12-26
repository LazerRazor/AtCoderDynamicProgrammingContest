#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;

    vector<int>winningState(k + 1, 0), a(n);

    for(auto &i : a)cin >> i;
    
    for(int i = 1; i <= k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[j] <= i) winningState[i] |= ~winningState[i - a[j]];
        }
    }

    cout << (winningState[k] ? "First" : "Second");
}