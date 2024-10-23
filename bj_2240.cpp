#include<bits/stdc++.h>
using namespace std;

int t, w, ret, a[1004], dp[1004][2][34];

int jadoo(int idx, int tree, int cnt) { // 인덱스, 지금 내가 있는 위치, 움직일 수 있는 카운트
    if(cnt < 0) return -1e9; // 해당 경우의 수 배제
    if(idx == t) return 0; // 모든 부분 탐색이 종료됨
    int &ret = dp[idx][tree][cnt];
    if(~ret) return ret;
    
    // cnt - 1은 결국 내가 움직이는 것 -> 즉 내가 있는 나무의 위치가 변경됨(tree ^ 1)
    // 시간초가 계속 증가하니까 idx + 1
    // 그냥 cnt는 움직이지 않음 -> 즉, 내가 있는 나무의 위치도 변경되지 않음
    return ret = max(jadoo(idx + 1, tree^1, cnt - 1), jadoo(idx + 1, tree, cnt)) + (tree == a[idx] - 1);
}

int main() {
    cin >> t >> w;
    for(int i = 0; i < t; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << max(jadoo(0, 1, w - 1), jadoo(0, 0, w));

    cout << ret;
    return 0;
}