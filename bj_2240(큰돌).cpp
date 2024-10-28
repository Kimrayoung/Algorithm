#include<bits/stdc++.h>
using namespace std;

int t, w, ret, a[1004], dp[1004][2][34];

int dfs(int idx, int tree, int cnt) { // 인덱스, 지금 내가 있는 위치, 움직일 수 있는 카운트
    if(cnt < 0) return -1e9; // 해당 경우의 수 배제
    if(idx == t) return 0; // 모든 부분 탐색이 종료됨
    
    int &ret = dp[idx][tree][cnt];
    // 메모이제이션 기법을 사용하는 코드 -> 이미 계산한 값들을 저장해두고 필요한 경우 다시 계산하지 않고 저장된 값을 사용함
    // ~ret는 ret의 모든 비트를 반전시킨다 
    // 이 코드에서 ret의 초기값을 -1로 설정하고 있고 -1이라면 이는 아직 계산되지 않음을 나타낸다
    // if(~ret)는 if(ret != -1)와 동일한 의미이다.
    if(ret >= 0) return ret;
    
    // cnt - 1은 결국 내가 움직이는 것 -> 즉 내가 있는 나무의 위치가 변경됨(tree ^ 1)
    // 시간초가 계속 증가하니까 idx + 1
    // 그냥 cnt는 움직이지 않음 -> 즉, 내가 있는 나무의 위치도 변경되지 않음
    return ret = max(dfs(idx + 1, tree^1, cnt - 1), dfs(idx + 1, tree, cnt)) + (tree == a[idx] - 1);
}

int main() {
    cin >> t >> w;
    for(int i = 0; i < t; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    // 0초에서 시작하므로 둘다 0
    // 2번 나무로 이동했음이 1, 1번 나무에 그대로 있음이 0
    // 2번 나무로 이동했기 때문에 w - 1, 1번 나무에 그대로 있으니까 w
    cout << max(dfs(0, 1, w - 1), dfs(0, 0, w));

    cout << ret;
    return 0;
}