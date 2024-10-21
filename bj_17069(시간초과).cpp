#include <bits/stdc++.h>
using namespace std;
int n, ret;
int a[34][34], visited[34][34];
// i = 0: (0, 1) -> 가로 /i = 1: (1, 0) -> 세로/i = 2: (1, 1) -> 대각선
int dy[] = {0, 1, 1};
int dx[] = {1, 0, 1};

void dfs(int y, int x, int dir) {
    if (y == n && x == n) {
        ret++;
        return;
    }

    for(int i = 0; i < 3; i++) {
        if((dir == 0 && i == 1) || (dir == 1 && i == 0)) continue;
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny > n || nx > n || a[ny][nx] == 1 || visited[ny][nx]) continue;
        if(dir == 2 && (a[y + 1][x] == 1 || a[y][x + 1] == 1)) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, i);
        visited[ny][nx] = 0;
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    dfs(1, 2, 0);
    cout << ret << "\n";
    return 0;
}