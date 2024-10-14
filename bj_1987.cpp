#include<bits/stdc++.h> 
using namespace std;
int r, c, mx;
char a[24][24];
int visited[24][24];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
map<char, int>mp;

void dfs(int y, int x, int sum) {
    if(mx < sum) mx = sum;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if(mp[a[ny][nx]] || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        mp[a[ny][nx]] = 1;
        // sum++ -> 이게 아닌 이유가 예를 들어 [0][3]위치 부터 시작하는 게 가장 크다면 해당 위치부터 sum을 다시 시작해야 함
        // 즉, sum을 계속 누적하는 것이 아니라 특정 위치에의 sum을 가지고 해당 sum부터 확인하는 것이므로 sum을 재귀함수의 인자로 넣어줘야 한다
        dfs(ny, nx, sum + 1);
        // 원복 -> 모든 위치를 다 확인해야함
        visited[ny][nx] = 0;
        mp[a[ny][nx]] = 0;
    }
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    
    mp[a[0][0]] = 1;
    dfs(0, 0, 1);
    cout << mx << "\n";


    return 0;
} 


// LIS: Longestr Increase Sequence
// 숫자를 시각화 하는 것이 굉장히 중요하다(증가하는 감소하는 배열을 찾을 때)
