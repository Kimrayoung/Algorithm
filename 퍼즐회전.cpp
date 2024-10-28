#include <bits/stdc++.h>
using namespace std;
void normalize(vector<pair<int, int>> &piece) {
    int minY = INT_MAX, minX = INT_MAX;
    for (const auto &p : piece) {
        minY = min(minY, p.first);
        minX = min(minX, p.second);
    }
    for (auto &p : piece) {
        p.first -= minY;
        p.second -= minX;
    }
    sort(piece.begin(), piece.end());
}

void rotate(vector<pair<int, int>>& a) {
    for(int i = 0; i < a.size(); i++) {
        int temp = a[i].first;
        a[i].first = a[i].second;
        a[i].second = -temp;
    }
    normalize(a);
}

void printRotate(vector<pair<int, int>>& a) {
    for(int i = 0; i < a.size(); i++) {
        cout << "y: " << a[i].first << " x: " << a[i].second << "\n";
    }
}

int main() {
    vector<pair<int, int>> a;
    a.push_back({1, 1});
    a.push_back({1, 2});
    a.push_back({2, 1});
    for(int i = 0; i < 4; i++) {
        rotate(a);
        cout << "90\n";
        printRotate(a);
    }
    return 0;
}