#include <bits/stdc++.h>

using namespace std;
int t,a,d[54][54];
string s; 
char b[54][54];
bool check[54][54];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

// 좌표 내에 포함하는 지 체크한다
bool in(int aa,int bb){
    return(1<=aa && aa<=t && 1<=bb && bb<=a);
}  
int down(int y,int x){
    // 좌표를 벗어나거나 구멍이면 return 0 -> 갈 수 없음
    if(!in(y, x) || b[y][x] == 'H') return 0;
    // 이미 갔던 곳이라면 순회를 하는 코드이니까 -1을 출력하고 main함수 종료
    if(check[y][x]){
        cout << -1 << "\n";
        exit(0);
    } 
    //현재 좌표로 이동한 횟수 -> 이미 해당 위치에 숫자가 있다면 
    cout << "y: " << y << " x: " << x << "\n";
    int &ret = d[y][x];
    if(ret) return ret;
    
    check[y][x] = 1;
    int value = (int)b[y][x] - '0';
    for(int i = 0; i < 4; i++){
        // 해당 좌표만큼 이동한다
        int ny = y + dy[i] * value;
        int nx = x + dx[i] * value;
        ret= max(ret, down(ny, nx) + 1);
    }
    // 원복을 해준다 -> 갔던 곳을 다시 가서 체크해줄 수도 있기 때문에
    check[y][x] = 0;
    return ret;
}
int main(){
    cin >> t >> a;
    for(int i = 1; i <= t; i++){
        cin >> s;  
        for(int j = 1; j <= a; j++){
            b[i][j] = s[j - 1];
        }
    }
    cout << down(1, 1) << "\n";
}
