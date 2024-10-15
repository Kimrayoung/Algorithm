#include<bits/stdc++.h>
using namespace std;
int visited[104][104], n, m;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int x, int y, vector<vector<int>>& a) {
    queue<pair<int, int>> q;
    visited[x][y] = 1;
    q.push({x, y});
    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        printf("x: %d, y: %d", x, y);
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(a[ny][nx] == 1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return;
}

int main()
{   
    vector<vector<int>> maps = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1}
    };
    n = maps.size();
    m = maps[0].size();
    int answer = 0;
    bfs(0, 0, maps);
    // printf("%d", visited[n][m]);
    return 0;
}