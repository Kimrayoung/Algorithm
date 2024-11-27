#include<bits/stdc++.h>
using namespace std;
//dp1 -> 최소 연산 횟수, dp2 -> 어떤 숫자에서 왔는지(prev)
int dp1[1000000], dp2[1000000],ret = 987654321, n;
vector<int> path;

// void go(int num, int cnt, int prev) {
//     cout << "num: " << num << "cnt: " << cnt << "\n";
//     if (num == 1) {
//         if (ret > cnt) {
//             ret = cnt;
//             dp2[1] = prev;
//         }
//         return;
//     }

//     int &tempCnt = dp1[num];
//     int &next = dp2[num];
//     if(tempCnt && next) return;

//     if (num % 3 == 0) {
//         go(num / 3, cnt + 1, num);
        
//     }
//     if (num % 2 == 0) go(num / 2, cnt + 1, num);
//     go(num - 1, cnt + 1, num);
//     return;
// }

// int main() {
//     cin >> n;
//     go(0, n);
// }

void dfs(int num, int cnt, vector<int>& prevs) {
    if(num == 1) {
        if (ret > cnt) {
            ret = cnt;
            path = prevs;
        }
        return;
    }

    // dp1이 -1이 아니다 -> 이미 해당 숫자를 몇번에 갈 수 있는지 확인을 했음
    // 근데 그 확인한 숫자가 최소여야 한다 -> 현재, dp[cnt]에 있는 숫자가 cnt보다 작으면 최소
    if(dp1[num] != -1 && dp1[num] <= cnt) return;
    dp1[num] = cnt;

    if(num % 3 == 0) {
        prevs.push_back(num / 3);
        dfs(num / 3, cnt + 1, prevs);
        prevs.pop_back(); // 원복
    }
    if(num % 2 == 0) {
        prevs.push_back(num / 2);
        dfs(num / 2, cnt + 1, prevs);
        prevs.pop_back();
    }

    prevs.push_back(num - 1);
    dfs(num - 1, cnt + 1, prevs);
    prevs.pop_back();
}

int main() {
    cin >> n;
    fill(dp1, dp1 + n + 1, -1);
    vector<int> prevs = {n}; // prevs에 시작숫자인 n을 넣고 싲가한다
    dfs(n, 0, prevs);
    cout << ret << "\n";
    for(int i = 0; i <= ret; i++) {
        cout << path[i] << " ";
    }
}

// int main() {
//     cin >> n;
//     // go(n,0);
//     fill(dp1, dp1 + n + 1, INT_MAX);
//     dp1[1] = 0;
//     for(int i = 2; i <= n; i++) {
//         if(dp1[i] > dp1[i - 1] + 1) {
//             dp1[i] = dp1[i - 1] + 1;
//             dp2[i] = i - 1;
//         }
        

//         if(i % 2 == 0) {
//             if (dp1[i] > dp1[i / 2] + 1) {
//                 dp1[i] = dp1[i/2] + 1;
//                 dp2[i] = i/2;
//             }
//         }

//         if(i % 3 == 0) {
//             if (dp1[i] > dp1[i / 3] + 1) {
//                 dp1[i] = dp1[i/3] + 1;
//                 dp2[i] = i/3;
//             }
//         }
//     }
//     cout << dp1[n] << "\n";
    
//     int current = n;
//     while(current != 0) {
//         cout << current << " ";
//         current = dp2[current];
//     }
//     return 0;
// }