#include<bits/stdc++.h>
using namespace std;

int n, m, k, ty, tx, tage;
int yangboon[11][11]; // 겨울에 추가되는 양분
int sumToil[11][11];
map<pair<int, int>, vector<int>> trees;
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool compare(int a, int b) {
    return a > b;
}

int go() {
    for(auto itr = trees.begin(); itr != trees.end(); itr++) {
        cout << "y: " << itr->first.first << " x: " << itr->first.second << "\n";
        int treeSum = 0;
        // 봄 -> 나이를 먹음
        for(auto tree = itr->second.begin(); tree != itr->second.end(); tree++) {
            *tree += 1;
            treeSum += *tree; 
        }
        // 나무가 양분을 먹지 못하고 죽음 -> 죽은 나무의 나이 / 2가 양분으로
        if (treeSum > yangboon[itr->first.first][itr->first.second]) {
            sort(itr->second.begin(), itr->second.end());
        }
        // 가을 -> 나무 번식
        for(auto tree = itr->second.begin(); tree != itr->second.end(); tree++) {
            if(*tree % 5 == 0) { // 5일때만 번식가능
                for(int i = 0; i < 8; i++) {
                    int ny = itr->first.first + dy[i];
                    int nx = itr->first.second + dx[i];
                    if (ny >= n || nx >= n || ny < 0 || nx < 0) continue; // 범위초과
                    // 해당 위치에 나무가 하나도 없음
                    if (trees.find({itr->first.first, itr->first.first}) == trees.end()) {
                        trees[{ny, nx}].push_back(1);
                    } else { // 해당 위치에 나무가 여러개
                        vector<int> temp;
                        temp.push_back(1);
                        trees.insert({{ny, nx}, temp});
                    }
                }
            }
        } // 가을
        //겨울 -> S2D2가 양분추가
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <=n; j++) {
                sumToil[i][j] += yangboon[i][j];
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=n; j++) {
            cin >> yangboon[i][j];
        }
    }
    // 처음에 토양은 모두 양분이 5
    memset(sumToil, 5, sizeof(sumToil));

    for(int i = 1; i <= m; i++) {
        cin >> tx >> ty >> tage;
        if(trees.find({ty, tx}) != trees.end()) {
            trees[{ty, tx}].push_back(tage);
        } else {
            vector<int> temp;
            temp.push_back(tage);
            trees.insert({{ty, tx}, temp});
        }
    }

    go();

    return 0;
}