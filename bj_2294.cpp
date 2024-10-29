#include <bits/stdc++.h>
using namespace std;

int n, k, dp[10001], INF = 987654321, coins[10001];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // memset(dp, INF, sizeof(dp));
    fill(dp, dp + 10001, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = coins[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
        // 오른쪽부터 탐색(즉, 큰 쪽부터 탐색할 경우) -> 누적이 안되도록함
        // for(int j = k; j >= coins[i]; j--) {
        //     dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        // }
    }
    for(int i = 0; i <= k; i++) {
        cout << i << ": " << dp[i] << "\n";
    }
    if (dp[k] == INF) cout << "-1\n";
    else cout << dp[k] <<"\n";
    return 0;
}