#include <bits/stdc++.h>
using namespace std;

int n, k, dp[100001], coins[100001];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    fill(dp, dp + 10001, 0);
    for(int i = 0; i < n; i++) {
        dp[coins[i]] += 1;
        for(int j = coins[i]; j <= k; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[k] <<"\n";
    return 0;
}