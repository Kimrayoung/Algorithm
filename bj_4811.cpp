#include<bits/stdc++.h>
using namespace std;
int a[1004], tc;
long long dp[31][31];

long long go(int pill, int halfPill) {
    // 음수의 경우는 확인할 수 없음
    if (halfPill < 0 || pill < 0) return 0;
    // 알약을 전체 다 소진했을 경우
    if (halfPill == 0 && pill == 0) {
        return 1; 
    }

    long long &ret = dp[pill][halfPill];
    // 이미 값을 구한 경우 그 값을 그대로 사용한다
    if(ret > 0) return ret; 
    // 반쪽자리 알약 먹었을 경우 + 한쪽자리 알약을 먹었을 경우
    return ret += go(pill, halfPill - 1) + go(pill - 1, halfPill + 1); //
}

int main() {
    while(true) {
        cin >> a[tc];
        if(a[tc] == 0) break;
        tc++;
    }

    for(int i = 0; i < tc; i++) {
        // 매번 DP는 0으로 초기화
        memset(dp, 0, sizeof(dp));
        cout << go(a[i], 0) << "\n";
    }

    return 0;
}