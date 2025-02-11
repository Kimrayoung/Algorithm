#include<bits/stdc++.h>
using namespace std;
int n, m, k, tx, ty, tage, ret;
int yangboon[11][11]; 
int robotToil[11][11];
map<pair<int, int>, vector<int>> trees;
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void go() {    
   // 봄과 여름 처리
    for(auto& itr : trees) {
        vector<int> tempTree;
        int dieTree = 0;

       sort(itr.second.begin(), itr.second.end());  // 어린 나무부터 양분을 먹음

        for(int age : itr.second) {
            if(yangboon[itr.first.first][itr.first.second] >= age) {
                yangboon[itr.first.first][itr.first.second] -= age;
                tempTree.push_back(age + 1); 
            } else {
                dieTree += age / 2;
            }
        }
        yangboon[itr.first.first][itr.first.second] += dieTree;
        itr.second = tempTree;
    }
    
   // 가을 - 나무 번식
    map<pair<int, int>, vector<int>> breeding;
    for(auto& itr : trees) {
        for(int age : itr.second) {
            if(age % 5 == 0) {
                for(int dir = 0; dir < 8; dir++) {
                    int ny = itr.first.first + dy[dir];
                    int nx = itr.first.second + dx[dir];
                    if(ny > n || nx > n || ny < 1 || nx < 1) continue;
                    breeding[{ny, nx}].push_back(1);
                }
            }
        }
    }
    
    for(auto& itr : breeding) {
        trees[itr.first].insert(trees[itr.first].end(), itr.second.begin(), itr.second.end());
    }
    
   // 겨울 - 양분 추가
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            yangboon[i][j] += robotToil[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> robotToil[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            yangboon[i][j] = 5;
        }
    }

    for(int i = 0; i < m; i++) {
        cin >> tx >> ty >> tage;
        trees[{tx, ty}].push_back(tage);
    }

    while(k--) {
        go();
    }

    ret = 0;
    for(auto& itr : trees) {
        ret += itr.second.size();
    }
    
    cout << ret << "\n";
    return 0;
}