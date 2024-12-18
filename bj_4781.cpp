#include <bits/stdc++.h>
using namespace std;
int n, ret, m1, m2, c;
int dp[100004];

int main() {
    while(true) {
        scanf("%d %d.%d", &n, &m1, &m2);
        if (n == 0) { break; }
        int cost = m1 * 100 + m2; // int로 변환
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) {
            scanf("%d %d.%d", &c, &m1, &m2);
            int p = m1 * 100 + m2;
            for(int j = p; j <= cost; j++) {
                if (dp[j] < dp[j - p] + c) { dp[j] = dp[j - p] + c; }
            }
        }
    }

    return 0;
}

// 동전2, 동전1문제랑 비슷함
// 나는 p ~ cost까지 1씩 더하면서 할 생각을 하지 못했음
// 어떻게 하면 알 수 있지?