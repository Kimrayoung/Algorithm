#include <bits/stdc++.h> 
#define MAX_N 16
const int INF = 987654321;
using namespace std; 
int n, dp[MAX_N][1 << MAX_N], dist[MAX_N][MAX_N];

void printDP() {
    cout << "DP 배열 상태:\n";
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] == -1) {
                cout << "INF\t";
            } else {
                cout << dp[i][j] << "\t";
            }
        }
        cout << "\n";
    }
}

// here는 idx
// [1, 0, 1, 1] -> 1011로 표현될 수 있다.
//즉, 16개의 배열을 만든는 것이 아니라 1011이런식으로 비트마스킹으로 나타낸다
int tsp(int here, int visited){
    if(visited == (1 << n) - 1){ // 모든 지점을 방문
        // INF를 하는 이유가 마지막 지점에서 원래 지점까지 돌아오는 경로가 없을 수도 있으니까
        return dist[here][0] ? dist[here][0] : INF; 
    }
    // 메모이제이션 시작
    int &ret = dp[here][visited];
    if(ret != -1) return ret;
    ret = INF; // 최소값을 구하는 문제니까 최대값으로 두고 시작한다
    for(int i = 0; i < n; i++){
        if(visited & (1 << i)) continue; // 이미 방문
        if(dist[here][i] == 0) continue; // 경로가 없음
        ret = min(ret, tsp(i, visited | (1 << i)) + dist[here][i]);
    }
\
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> dist[i][j];
        }
    }
    memset(dp, -1, sizeof(dp)); // dp라는 배열을 초기화환다.
    // 배열을 0번째 index부터 받으니까
    // 1은 0번째 도시는 방문한 상태에서 시작한다
    cout << tsp(0, 1) << '\n';
    return 0;
}
