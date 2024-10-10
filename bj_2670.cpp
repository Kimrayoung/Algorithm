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
        //첫번째에 넣은게 가장 클 수도 있기 때문에 이 부분이 반드시 필요하다
        if (tempSum > ret) ret = tempSum;
        for(int j = i + 1; j < n; j++) {
            tempSum *= v[j];
            if (tempSum > ret) ret = tempSum;
        }
    }
    printf("%.3f\n", ret);
} 
