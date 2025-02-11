#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17) return true;
    return false;
}

double combination(int n, int r) {
    if (r > n) return 0;
    if (r * 2 > n) r = n - r;
    if (r == 0) return 1;

    double result = n;
    for (int i = 2; i <= r; i++) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

double binomial(int n, int r, double p) {
    if (r > n) return 0;
    // pow(p, r) -> 성공할 확률
    // pow(1-p, n-r) -> 실패할 확률
    return combination(n, r) * pow(p, r) * pow(1-p, n-r);
}

int main() {
    double a, b;
    cin >> a >> b;
    a /= 100;
    b /= 100;
    
    double notPrime = 0;
    
    // 둘 다 소수가 아닌 경우의 확률 계산
    for (int i = 0; i <= 18; i++) {
        for (int j = 0; j <= 18; j++) {
            if (!isPrime(i) && !isPrime(j)) {
                notPrime += binomial(18, i, a) * binomial(18, j, b);
            }
        }
    }
    
    cout << fixed;
    cout.precision(15);
    cout << 1 - notPrime << endl;
    
    return 0;
}