#include <bits/stdc++.h> 
using namespace std; 
int r, t, c, ret;
int a[54][54], dustA[54][54];
vector<pair<int, int>> cleanDir;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void printDust() {
    cout << "--------------------dustMap-----------\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << dustA[i][j] << " ";
        }
        cout << "\n";
    }
}

void makeDust(int y, int x) {
    int dir = 0;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if(a[ny][nx] == -1) continue;
        dustA[ny][nx] += a[y][x] / 5;
        dir++;
    }
    dustA[y][x] += a[y][x] - (a[y][x] / 5) * dir;
    return;
}

void cleanDust(int y, int x, int dir) {
    if(dir == 0) {
        // 공기청정기의 윗 부분 (반시계방향)
        for (int i = y - 1; i > 0; i--) a[i][0] = a[i - 1][0]; // 아래로 이동
        for (int i = 0; i < c - 1; i++) a[0][i] = a[0][i + 1]; // 오른쪽으로 이동
        for (int i = 0; i < y; i++) a[i][c - 1] = a[i + 1][c - 1]; // 위로 이동
        for (int i = c - 1; i > 1; i--) a[y][i] = a[y][i - 1]; // 왼쪽으로 이동
        a[y][1] = 0; // 청정기 근처는 먼지가 없다
    } else {
        // 공기청정기의 아랫 부분 (시계방향)
        for (int i = y + 1; i < r - 1; i++) a[i][0] = a[i + 1][0]; // 위로 이동
        for (int i = 0; i < c - 1; i++) a[r - 1][i] = a[r - 1][i + 1]; // 오른쪽으로 이동
        for (int i = r - 1; i > y; i--) a[i][c - 1] = a[i - 1][c - 1]; // 아래로 이동
        for (int i = c - 1; i > 1; i--) a[y][i] = a[y][i - 1]; // 왼쪽으로 이동
        a[y][1] = 0; // 청정기 근처는 먼지가 없다
    }
}

// void cleanDust(int y, int x, int dir) {
//     if(dir == 0) {
//         // x: 1 ~ c(->)
//         int temp = a[y][c - 1];
//         for(int i = c - 1; i > 1; i--) {
//             a[y][i] = a[y][i - 1];
//         }
//         // 위쪽
//         int temp2 = a[0][c - 1];
//         for(int i = 0; i < y; i++) {
//             if(i == y - 1) a[i][c - 1] = temp;
//             else a[i][c - 1] = a[i + 1][c - 1]; 
//         }
//         // 왼쪽
//         temp = a[0][0];
//         for(int i = 0; i < c - 1; i++) {
//             if(i == c - 2) a[0][i] = temp2;
//             else a[0][i] = a[0][i + 1];
//         }
//         for(int i = y - 1; i > 0; i--) {
//             if(i == 1) a[i][0] = temp;
//             else a[i][0] = a[i - 1][0];
//         }
//     } else {
//         int temp = a[y][c - 1];
//         for(int i = c - 1; i > x; i--) {
//             a[y][i] = a[y][i - 1];
//         }
//         //down
//         int temp2 = a[r - 1][c - 1];
//         for(int i = r - 1; i > y; i--) {
//             if(i == y + 1) a[i][c - 1] = temp;
//             else a[i][c - 1] = a[i - 1][c - 1];
//         }
//         temp = a[r - 1][0];
//         for(int i = 0; i < c - 1; i++) {
//             if(i == c - 2) a[r - 1][i] = temp2;
//             else a[r - 1][i] = a[r - 1][i + 1];
//         }
//         for(int i = r - 1; i > y; i--) {
//             if(i == y + 1) a[i][0] = temp;
//             else a[i][0] = a[i - 1][0]; 
//         }
//     }
// }

int main() {
	cin >> r >> c >> t;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
            if(a[i][j] == -1) cleanDir.push_back({i, j});
        }
    }

    for(int k = 0; k < t; k++) {
        memset(dustA, 0, sizeof(dustA)); // 먼지 확산 맵 다시 초기화
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                // if(a[i][j] > 0) makeDust(i, j);
                if(a[i][j] == 0 || a[i][j] == -1) continue;
                if(a[i][j] < 5) dustA[i][j] += a[i][j];
                else makeDust(i, j);
            }
        }

        // 기존의 맵을 확산된 맵으로 치환해주기
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(a[i][j] != -1) {
                    a[i][j] = dustA[i][j];
                }
            }
        }

        // 공기청정기 가동
        cleanDust(cleanDir[0].first, cleanDir[0].second, 0);
        cleanDust(cleanDir[1].first, cleanDir[1].second, 1);
    }
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(a[i][j] != 0) ret += a[i][j];
        }
    }

    cout << ret + 2 << "\n";
	return 0;
} 