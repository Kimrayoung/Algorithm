#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
int n;
double temp, ret, tempSum;
vector<double> v;


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf", &temp);
        v.push_back(temp);
    }
    for(int i = 0; i < n; i++) {
        tempSum = v[i];
        if (tempSum > ret) ret = tempSum;
        for(int j = i + 1; j < n; j++) {
            tempSum *= v[j];
            if (tempSum > ret) ret = tempSum;
        }
    }
    printf("%.3f\n", ret);
} 
