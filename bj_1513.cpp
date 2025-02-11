#include<bits/stdc++.h>
using namespace std;
int n, m, c, a[51][51], tempY, tempX, ret, possible;
const int mod = 1000007;
int dp[51][51][51][51];
int dy[] = {1, 0};
int dx[] = {0, 1};
int visited[54][54];

int dfs(int y, int x, int possible, int prev) {
    if(y > n || x > m) return 0;
    if(y == n && x == m) {
        if(possible == 0 && a[y][x] == 0) return 1;
        if(possible == 1 && a[y][x] > prev) return 1;
        return 0; 
    }

    int &ret = dp[y][x][possible][prev];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < 2; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(a[y][x] == 0) {
            // ret는 현재까지의 값이 누적된 값이된다
            ret = (ret + dfs(ny, nx, possible, prev)) % mod;
        } else if (a[y][x] > prev) {
            ret = (ret + dfs(ny, nx, possible - 1, a[y][x])) % mod;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> c;
    for(int i = 1; i <= c; i++) {
        cin >> tempY >> tempX;
        a[tempY][tempX] = i;
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i <= c; i++) {
        cout << dfs(1, 1, i, 0) << " ";
    }

    return 0;
}

// void dfs(int y, int x, int now) {
//     // cout << "y: " << y << " x: " << x << "\n";
//     if (y == n - 1 && x == m - 1) { 
//         // cout << "one Finish" << possible << "\n";
//         if (possible == 0) ret += 1; 
//         return;
//     }
//     for(int i = 0; i < 2; i++) {
//         int ny = y + dy[i];
//         int nx = x + dx[i];
//         // cout << "ny: " << ny << " nx: " << nx << "\n";
//         if(ny >= n || nx >= m || ny < 0 || nx < 0 || visited[ny][nx]) continue;
//         if(a[ny][nx]) {
//             cout << "possible: " << possible << " a: " << a[ny][nx] << " now: " << now << "\n";
//             if(possible < 0) continue;
//             if(possible <= a[ny][nx]) continue;
//             visited[ny][nx] = 1;
//             possible -= 1;
//             dfs(ny, nx, a[ny][nx]);
//             visited[ny][nx] = 0;
//             possible += 1;
//         } else {
//             visited[ny][nx] = 1;
//             dfs(ny, nx, now);
//             visited[ny][nx] = 0;
//         }
        
//     }
// }

// int main() {
//     cin >> n >> m >> c;
//     for(int i = 0; i < c; i++) {
//         cin >> tempY >> tempX;
//         a[tempY - 1][tempX - 1] = i + 1;
//     }
//     for (int i = 0; i <= c; i++) {
//         ret = 0;
//         memset(visited, 0, sizeof(visited));
//         possible = i;
//         dfs(0, 0, 0);
//         cout << ret << " ";
//     }
//     return 0;
// }

//1. 트래블링 -> 종료조건 미리 확인 or 나중에 확인
//2. 종료조건
//3. 메모이제이션