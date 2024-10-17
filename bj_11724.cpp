#include <bits/stdc++.h>
using namespace std;

int n, m, temp1, temp2, ret, visited[1002];
vector<int> a[1002];

void dfs(int idx) {
    visited[idx] = 1;
    for(int i = 0; i < a[idx].size(); i++) {
        if(visited[a[idx][i]]) continue;
        dfs(a[idx][i]);
    }
    return;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> temp1 >> temp2;
        a[temp1].push_back(temp2);
        a[temp2].push_back(temp1);
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 0; j < a[i].size(); j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
            ret++;
        }
    }

    cout << ret << "\n";
    return 0;
}