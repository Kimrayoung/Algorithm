#include<bits/stdc++.h>
using namespace std;
int a[101], n;
long long dp[101][21]; // idx번째 위치에서 현재까지의 합이 sum일때, 가능한 모든 수식의 개수

long long dfs(int number, int idx) {
    // cout << "number: " << number << " idx: " << idx << "\n";
    if (number > 20 || number < 0) return 0;
    if (idx == n - 1) return number == a[n - 1]; // 합이 동일하다면 1 동일하지 않다면 0이 return되서 쌓이게 됨

    long long &ret = dp[idx][number];
    if (ret != -1) return ret;

    return ret = dfs(number + a[idx], idx + 1) + dfs(number - a[idx], idx + 1); // 해당 인덱스에서의 방법의 개수가 저장됨
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    
    cout << dfs(a[0], 1) << "\n";
    return 0;
}
// 만들 수 있는 수는 0이상 20이하
// 사이에 + 혹은 -를 넣어서 만들어야 한다.