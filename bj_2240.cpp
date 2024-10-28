#include <bits/stdc++.h>
using namespace std;
int t, w, apple[1004], temp;
int dp[1004][34][2];

// int go(int now, int m, int tree) {
//     // 시간초가 다 되었거나 더 이상 움직일 수 없을때
//     if(now == t || m < 0) return 0;

//     return max(go(now + 1, m, tree), go(now + 1, m - 1, tree ^ 1)) + (tree == apple[now]);
// }

int go(int now, int m, int tree) {
    // 시간초가 다 되었거나 더 이상 움직일 수 없을때
    if(now == t || m < 0) return 0;
    int &ret = dp[now][m][tree];
    // 이미 확인한 곳은 그냥 바로 해당 값을 사용한다
    if(ret >= 0) return ret;
    return ret = max(go(now + 1, m, tree), go(now + 1, m - 1, tree ^ 1)) + (tree == apple[now]);
}

int main() {
    cin >> t >> w;
    for(int i = 0; i < t; i++) {
        cin >> temp;
        apple[i] = temp - 1; // 사과가 떨어지는 위치를 1이랑 2에서 0이랑 1로 변경 -> 비트마스킹으로 확인하기 위해서 
    }
    memset(dp, -1, sizeof(dp));
    cout << max(go(0, w, 0), go(0, w - 1, 1)) << "\n";
    return 0;
}
