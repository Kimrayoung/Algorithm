#include<bits/stdc++.h>
using namespace std;
struct H {
    int y, x, d, n;
};
int n, k, a[13][13], x, y, z, ret, flag;
vector<int> b[13][13]; // 말들을 옮길때 쓰는 배열
H h[13]; // 실제 말의 정보 저장

int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

void print(vector<int> m) {
    for(int i = 0; i < m.size(); i++) {
        cout << m[i] << " ";
    }
    cout << "\n";
}

void print2() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << b[i][j].size() << " ";
        }
        cout << "\n";
    }
}

// 이동할 말들 찾기
vector<int> moveHorse(H horse, int ny, int nx, int needReverse) {
    int i = 0;
    int start, end;

    // 맵에 있는 말들을 어디서부터 이동시켜야할지 -> 말들의 이동 시작말 찾기
    // ex. 12345순으로 쌓여있고 345를 찾아야 한다면 i = 2(start = 2가 됨) -> 즉, 시작위치가 i = 2부터 i = 4까지 이동
    while(true) {
        if (b[horse.y][horse.x][i] == horse.n) {
            start = i;
            break;
        } 
        i += 1;
    }

    // 항상 마지막 말은 이동하게 되므로
    end = b[horse.y][horse.x].size();
    // 이동할 말 
    vector<int> move(b[horse.y][horse.x].begin() + start, b[horse.y][horse.x].begin() + end);
    // 원래 위치에서 이동한 말 제거 -> 즉, 맵에서 제거(b에서 제거)
    b[horse.y][horse.x].erase(b[horse.y][horse.x].begin() + start, b[horse.y][horse.x].begin() + end);

    // 말 배열에서 실제 말의 위치 변경(h 배열에서 위치 업데이트)
    for(int i = 0; i < move.size(); i++) {
        int n = move[i];
        h[n].y = ny;
        h[n].x = nx;
    }
    // 거꾸로 말을 쌓아야 하는 경우
    if (needReverse) {
        reverse(move.begin(), move.end());
    }

    return move;
}

void dfs(H horse) {
    if (b[horse.y][horse.x].size() == 4) {
        flag = 1;
        return;
    }

    int ny = dy[horse.d] + horse.y;
    int nx = dx[horse.d] + horse.x;

    // 위치를 벗어나거나 다음 위치가 파란색일때(2)
    if (ny < 1 || nx < 1 || ny > n || nx > n || a[ny][nx] == 2) {
        if (h[horse.n].d == 0) h[horse.n].d = 1; // 말들 배열에 있는 실제 말의 방향 변경(h배열에 있는 말)
        else if (h[horse.n].d == 1) h[horse.n].d = 0;
        else if (h[horse.n].d == 2) h[horse.n].d = 3;
        else if (h[horse.n].d == 3) h[horse.n].d = 2;
        horse.d = h[horse.n].d;  // 현재 말의 방향도 업데이트 -> 맵에 있는 말의 방향 변경(b배열에서 해당 위치의 해당)
        int nny = dy[horse.d] + horse.y;
        int nnx = dx[horse.d] + horse.x;

        if (nny < 1 || nnx < 1 || nny > n || nnx > n || a[nny][nnx] == 2) {
            return;
        }
        else {
            vector<int> horses = moveHorse(horse, nny, nnx, a[nny][nnx]);
            b[nny][nnx].insert(b[nny][nnx].end(), horses.begin(), horses.end());
            if (b[nny][nnx].size() >= 4) {
                flag = 1;
                return;
            };
        }
    }
    // 다음 맵이 흰색일 경우
    else if (a[ny][nx] == 0) {
        vector<int> horses = moveHorse(horse, ny, nx, 0);
        b[ny][nx].insert(b[ny][nx].end(), horses.begin(), horses.end());
        if (b[ny][nx].size() >= 4) {
            flag = 1;
            return;
        };
    } else if (a[ny][nx] == 1) { // 다음 맵이 빨간색일 경우
        vector<int> horses = moveHorse(horse, ny, nx, 1);
        b[ny][nx].insert(b[ny][nx].end(), horses.begin(), horses.end());
        if (b[ny][nx].size() >= 4) {
            flag = 1;
            return;
        };
    } 
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= k; i++) {
        cin >> y >> x >> z;
        b[y][x].push_back(i);
        h[i].y = y;
        h[i].x = x;
        h[i].d = z - 1;
        h[i].n = i;
    }
    
    while(true) {
        if (flag == 1 || ret >= 1000) break;
        ret += 1;
        for(int i = 1; i <= k; i++) {
            dfs(h[i]);
        }
    }
    
    if(flag == 0) cout << -1 << "\n";
    else cout << ret << "\n";
    return 0;
}

//흰색 -> 그 방향으로 이동(0)
// 빨간색 -> 이동한 후에 쌓여있는 말의 순서를 변경(1)
// 파란색 + 벗어나는 경우 -> 이동방향을 반대로 하고 이동(2)
// 종료조건 -> 말이 4개 이상쌓이는 경우