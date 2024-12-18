#include <bits/stdc++.h>
using namespace std;
int n, t, k, s, dp[10004];

int main() {
    cin >> n >> t;
    // cout << n << t;
    for(int i = 0; i < n; i++) {
        cin >> k >> s;
        for(int j = t; j >= k; j--) {
            dp[j] = max(dp[j], dp[j - k] + s);
        }
    }

    cout << dp[t] << "\n";
    return 0;
}