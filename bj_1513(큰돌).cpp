#include<bits/stdc++.h>
using namespace std;
int n, m, c, y, x, a[51][51], dp[51][51][51][51];
const int mod = 1000007;
int go(int y, int x, int cnt, int prev){
    if(y > n || x > m) return 0; // 맵에서 벗어난 경우 -> 여기서 맵 벗어났는지 체크를 하면 아래 if (a[y][x] == 0)에서 안해줘도 된다
    if(y == n && x == m){ //학원 도착
        // cnt == 0이어야 하는 이유가 무조건 마지막에 도착했을때 주어진 오락실 횟수만큼 오락실을 들려야 하기 때문이다
        if(cnt == 0 && a[y][x] == 0) return 1; //오락실이 아닌 경우 -> 모두 다 소거를 해야 한다
        //이때는 도착위치가 오락실인 것이기 때문에 cnt가 한번 남아이었어야 하고 그 전에 들린 오락실이 현재 오락실보다 순번이 낮아야 갈 수 있다
        if(cnt == 1 && a[y][x] > prev) return 1; //도착한 위치가 오락실인 경우 -> cnt가 1번 남아야 하고, 현재 오락실의 번호가 prev보다 커야 한다)
        return 0; // 그 외는 모두 불가능하다
    }
	int &ret = dp[y][x][cnt][prev];
	if(ret != -1) return ret;
    ret = 0;
    if(a[y][x] == 0){
        ret = (go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev)) % mod;
    }else if(a[y][x] > prev){
        ret = (go(y + 1, x, cnt - 1, a[y][x]) + go(y, x + 1, cnt - 1, a[y][x])) % mod;
    }
	return ret;
}
void fastIO(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
}
int main(){
    fastIO();
	memset(dp, -1, sizeof(dp)); // 한번도 갈 수 없는 경우도 있기 때문에 dp를 0으로 초기화하면 안된다
	cin >> n >> m >> c;
	for(int i = 1; i <= c; i++){
		cin >> y >> x;
		a[y][x] = i; // 오락실 순번
	}
	for(int i = 0; i <= c; i++){ // 오락실을 0번 들릴 경우, 1번 들릴 경우, 2번 들릴 경우 ...c번 들릴 경우
        cout << go(1, 1, i, 0) << " ";
	}
    return 0;
}
