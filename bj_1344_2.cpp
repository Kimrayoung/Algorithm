// #include <bits/stdc++.h>
// using namespace std;

// double probA, probB;

// bool isPrime(int n) {
//     if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17) return true;
//     return false;
// }

// double solve(int time, int scoreA, int scoreB, double curProb) {
//     if (time == 18) {
//         if (isPrime(scoreA) || isPrime(scoreB)) { return curProb; };
//         return 0;
//     }

//     double totalProb = 0;

//     totalProb += solve(time + 1, scoreA + 1, scoreB + 1, curProb * probA * probB);
//     totalProb += solve(time + 1, scoreA + 1, scoreB, curProb * probA * (1 - probB));
//     totalProb += solve(time + 1, scoreA, scoreB + 1, curProb * (1 - probA) * probB);
    
//     return totalProb;
// }


// int main() {
//     double a, b;
//     cin >> a >> b;
//     probA /= 100;
//     probB /= 100;
    
//     cout << fixed;
//     cout.precision(15);
//     cout << solve(0, 0, 0, 1.0) << "\n";
    
//     return 0;
// }

#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17) return true;
    return false;
}

// dp 초기화 함수
void initDP(double dp[19][19][19]) {
    for(int i = 0; i < 19; i++)
        for(int j = 0; j < 19; j++)
            for(int k = 0; k < 19; k++)
                dp[i][j][k] = 0;
    dp[0][0][0] = 1;
}

// 현재 시간의 모든 상태에서 다음 시간의 상태 계산
void calculate(int t, double dp[19][19][19], double a, double b) {
    for(int i = 0; i <= t; i++) {
        for(int j = 0; j <= t; j++) {
            if(dp[t][i][j] == 0) continue;
            
            double prob = dp[t][i][j];
            
            // A득점 B득점
            dp[t+1][i+1][j+1] += prob * a * b;
            // A득점 B무득점
            dp[t+1][i+1][j] += prob * a * (1-b);
            // A무득점 B득점
            dp[t+1][i][j+1] += prob * (1-a) * b;
            // A무득점 B무득점
            dp[t+1][i][j] += prob * (1-a) * (1-b);
        }
    }
}

// 최종 확률 계산
double getResult(double dp[19][19][19]) {
    double result = 0;
    for(int i = 0; i <= 18; i++) {
        for(int j = 0; j <= 18; j++) {
            if(isPrime(i) || isPrime(j)) {
                result += dp[18][i][j];
            }
        }
    }
    return result;
}

int main() {
    double a, b;
    cin >> a >> b;
    a /= 100;
    b /= 100;
    
    double dp[19][19][19];
    initDP(dp);
    
    // 각 시간마다 상태 계산
    for(int t = 0; t < 18; t++) {
        calculate(t, dp, a, b);
    }
    
    cout << fixed;
    cout.precision(15);
    cout << getResult(dp) << endl;
    
    return 0;
}

//nC2 + nC3 + nC5....