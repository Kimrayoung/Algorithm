#include<bits/stdc++.h>
using namespace std;
int n, k, w, v, dp[100001];

// int go(int nowW, int nowV, int idx) {
//     if (nowW > k) return -1;
    
//     int &ret = dp[nowW];
//     if (ret != -1) return ret;
//     go(nowW + w[idx], nowV + v[idx], idx + 1);
// }

void check() {
    
    cout << "\n";
}

int main() {
    cin >> n >> k; // n = 물품 수, k = 버틸 수 있는 무게
    for(int i = 0; i < n; i++) {
        cin >> w >> v;
        cout << w << v << "\n";
        for(int j = k; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
            cout << dp[j] << " ";
        }
        cout << "\n";
    }
    
    // go(0, 0, 0);
    cout << dp[k];
    return 0;
}