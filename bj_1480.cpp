#include<bits/stdc++.h>
using namespace std;
// int n, m, c, a[21], dp[11];

// void go(int bag, int jew) { // bag -> 지금 무슨 가방인지
//     if (bag == m) return;
//     if (dp[bag] >= c) return;

//     int &ret = dp[bag];
//     if (ret + a[jew] > c) return;
//     ret += a[jew];
    

// }

// int main() {
//     cin >> n >> m >> c;
//     for(int i = 0; i < n; i++) {
//         cin >> a[i];
//     }


//     return 0;
// }

typedef long long int ll;    
int n, m, c, a[24], backpack[24], dp[24][1 << 14][24];
int go(int here, int yamyam, int capacity){
	if(here == m) return 0; 
	int &ret = dp[here][yamyam][capacity]; 
	if(ret) return ret;  
    ret = max(ret, go(here + 1, yamyam, c)); 
	for(int i = 0; i < n; i++){  
        bool isbeforeYAM = (1 << i) & yamyam; 
        bool isYAMCAN = (capacity - a[i]) >= 0;
        if(!isbeforeYAM && isYAMCAN)ret = max(ret, go(here, yamyam | (1 << i), capacity - a[i]) + 1);
	}
	return ret; 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m >> c; 
	for(int i = 0; i < n; i++) cin >> a[i]; 
	cout << go(0, 0, c) << "\n";
	return 0; 
}