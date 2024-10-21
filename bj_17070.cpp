#include <bits/stdc++.h>
using namespace std;
int n, ret;
int a[20][20];
// (1, 0) -> 세로 이동 / (0, 1) -> 가로 이동 / (1, 1) 가로세로 이동
// dy = [1, 0, 1] dx = [0, 1, 1]을 하면 i = 0일때 세로로 이동하는게 되어버린다
// 그러므로 DFS(1, 2, 0)이 (1, 2)에 위치한 파이프를 세로로 이동시켜 버리는 결과가 된다
int dy[] = {0, 1, 1};
int dx[] = {1, 0, 1};

void dfs(int y, int x, int dir) {
    // printf("y: %d, x: %d, dir: %d\n", y, x, dir);
    if(y == n && x == n) { // 마지막 지점에 도착했을떄 도착하는 방법 + 1
        ret++;
        return;
    }

    for(int i = 0; i < 3; i++) {
        // 가로일때 -> 세로 이동 불가능, 세로일때 -> 가로이동 불가능
        // if((dir == 0 && i == 1) || (dir == 1 && i == 0)) continue;
        if((dir == 0 && i == 1) || (dir == 1 && i == 0)) continue;
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 1 || nx < 1 || ny > n || nx > n) continue;
        if(a[ny][nx]) continue;
        if(i == 2 && (a[y + 1][x] || a[y][x + 1])) continue; // a[y + 1][x], a[y][x+1]이 벽일 수도 있음
        dfs(ny, nx, i);
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) { // 문제 입력이 1부터 들어오기 때문에 
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    // 0은 가로로 이동
    dfs(1, 2, 0);
    cout << ret;
    return 0;
}

bool check(int y, int x, int d) {
    if(d == 0 || d == 2) {
        if(a[y][x] == 0) return true; // 즉, 가로 세로 일떄 해당 지점이 벽이 아님
        else if (d == 1) {
            // 대각선은 4방향이 모두 들어가야 한다
            // 하지만 a[y - 1][x - 1]은 이미 확인이 되어져 있다 -> 시작점이니까
            // 그럼 그걸 제외한 3가지 점은 확인을 해야 한다
            if(a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0) return true;
        }
    }
}

// int main() {
//     cin >> n;
//     for(int i = 1; i <= n; i++) { // 문제 입력이 1부터 들어오기 때문에 
//         for(int j = 1; j <= n; j++) {
//             cin >> a[i][j];
//         }
//     }

//     dp[1][2][0] = 1; // 처음에 가로로 놓고 오른쪽 점(끝점)을 기준으로 하기 때문에 
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= n; j++) {
//             /ㄴ/ 가로 방향으로 놓여진 파이프가 움직일 수 있는 경우의 수
//             // check에 들어가는 i, j + 1, 0은 파이프 끝 점의 다음 위치와 방향
//             // 즉, 1, 1에 있으면 (1, 2)등
//             if(check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0]; // 가로방향 파이프가 가로로 이동
//             if(check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0]; //가로 방향 파이프가 대각선으로 이동

//             // 세로 방향을 놓여진 파이프가 움직일 수 있는 경우
//             if(check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2]; // 세로방향 파이프가 세로로 이동
//             if(check(i + 1, j + 1, 2)) dp[i + 1][j + 1][1] += dp[i][j][2] // 세로방향 파이프가 대각선으로 이동

//             // 대각선 방향으로 놓여진 파이프가 움직일 수 있는 경우
//             if(check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1]; // 대각선 파이프가 가로로 이동
//             if(check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1]; // 대각선 방향 파이프가 세로로 이동
//             if(check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1]; // 대각선 방향 파이프가 대각선으로 이동
//         }
//     }

//     cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << "\n";
    
//     return 0;
// }