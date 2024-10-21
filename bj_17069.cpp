#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[34][34][3]; // long long으로 수정하여 큰 값도 저장 가능하도록 변경
int a[34][34]; // 문제에서 주어지는 격자 맵

// i = 0: (0, 1) -> 가로 / i = 1: (1, 0) -> 세로 / i = 2: (1, 1) -> 대각선
int dy[] = {0, 1, 1};
int dx[] = {1, 0, 1};

// 범위와 벽 여부를 함께 체크하는 함수
bool check(int y, int x, int dir) {
    if (y < 1 || x < 1 || y > n || x > n) return false; // 범위를 벗어나면 false
    if (dir == 0 || dir == 1) { // 가로 또는 세로
        if (a[y][x] == 0) return true; // 해당 칸이 벽이 아니면 이동 가능
    } else if (dir == 2) { // 대각선
        if (y - 1 >= 1 && x - 1 >= 1 && a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0) {
            return true; // 대각선은 3칸 모두 벽이 없어야 함
        }
    }
    return false;
}

int main() {
    // 입력 처리
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    dp[1][2][0] = 1; // 초기 상태: (1, 2)에 가로로 파이프가 놓여 있음

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) continue; // 벽이 있으면 스킵

            // 가로 상태에서 이동
            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0]; // 가로 -> 가로
            if (check(i + 1, j + 1, 2)) dp[i + 1][j + 1][2] += dp[i][j][0]; // 가로 -> 대각선

            // 세로 상태에서 이동
            if (check(i + 1, j, 1)) dp[i + 1][j][1] += dp[i][j][1]; // 세로 -> 세로
            if (check(i + 1, j + 1, 2)) dp[i + 1][j + 1][2] += dp[i][j][1]; // 세로 -> 대각선

            // 대각선 상태에서 이동
            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][2]; // 대각선 -> 가로
            if (check(i + 1, j, 1)) dp[i + 1][j][1] += dp[i][j][2]; // 대각선 -> 세로
            if (check(i + 1, j + 1, 2)) dp[i + 1][j + 1][2] += dp[i][j][2]; // 대각선 -> 대각선
        }
    }

    // 결과 출력: 마지막 칸에서 가로, 세로, 대각선 상태의 모든 경우의 수를 더함
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << "\n";
    
    return 0;
}
