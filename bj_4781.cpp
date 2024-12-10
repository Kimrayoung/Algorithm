#include <bits/stdc++.h>
using namespace std;
int n, ret, m1, m2, c;
int dp[100004];

int main() {
    while(true) {
        scanf("%d %d.%d", &n, &m1, &m2);
        if (n == 0) { break; }
        int cost = m1 * 100 * m2; // int로 변환
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) {
            scanf("%d %d.%d", &c, &m1, &m2);
            int p = m1 * 100 * m2;
            for(int j = p; j <= cost; j++) {
                if (dp[j] < dp[j - p] + c) { dp[j] = dp[j - p] + c; }
            }
        }
        // cout << "ret: " <<ret << "\n";
    }

    return 0;
}

