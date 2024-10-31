#include <bits/stdc++.h>
using namespace std;

int n, k, dp[10001], INF = 987654321, coins[10001];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // memset(dp, INF, sizeof(dp));
    fill(dp, dp + 10001, 0);
    for(int i = 0; i < n; i++) {
        dp[coins[i]] += 1;
        for(int j = coins[i]; j <= k; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    for(int i = 0; i <= k; i++) {
        cout << i << ": " << dp[i] << "\n";
    }
    if (dp[k] == INF) cout << "-1\n";
    else cout << dp[k] <<"\n";
    return 0;
}