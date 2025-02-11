#include <bits/stdc++.h>
using namespace std;
int a[11][11];
int paper[6] = {0, 5, 5, 5, 5, 5};
int result = 987654321;

void change(int y, int x, int size, int number) {
    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            a[i][j] = number;
        }
    }
}

bool checkSize(int y, int x, int size) {
    if(y + size > 10 || x + size > 10) return false;
    if(paper[size] == 0) return false;
    
    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if(!a[i][j]) return false;
        }
    }
    return true;
}

// 일단 중요한게 x먼저 이동 -> x가 끝에 도달하면 y 이동 -> y도 끝에 도달하면 탐색 종료 순이되는 것
// 0이면 다음 칸으로 이동(x 이동)
// x의 끝에 도달하면 다음 y칸으로 이동
void dfs(int y, int x, int cnt) {
    // 가로 줄 끝에 도달햇을때
    if(x == 10) {
        dfs(y + 1, 0, cnt);
        return;
    }

    // 모든 맵 탐색 완료
    if(y == 10) {
        result = min(result, cnt);
        return;
    }
    
    // 현재 위치가 0인 경우 -> 색종이를 붙일 필요가 없음
    if(a[y][x] == 0) {
        // 다음 칸으로 이동
        dfs(y, x + 1, cnt);
        return;
    }
    
    for(int size = 1; size <= 5; size++) {
        if(paper[size] > 0 && checkSize(y, x, size)) {
            paper[size]--;
            change(y, x, size, 0);
            dfs(y, x + 1, cnt + 1);
            paper[size]++;
            change(y, x, size, 1);
        }
    }
}

int main() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> a[i][j];
        }
    }
    
    dfs(0, 0, 0);
    
    if(result == 987654321) cout << -1;
    else cout << result;
    
    return 0;
}
// 일반적인 맵 탐색의 경우는 두 가지가 있다
// 1번 방향 기반 탐색
// 2번 순차탐색 -> 가로줄 기반