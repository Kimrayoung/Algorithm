#include <bits/stdc++.h>

using namespace std;
vector<string> ret;
int visited[10004], airports;

void dfs(string start, vector<vector<string>>& tickets) {
    if (ret.size() == airports) return;
    pair<string, int> next = {"", 0};
    for(int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] == start) {
            if (visited[i]) continue;
            if (next.first == "") {
                next.first = tickets[i][1];
                next.second = i;
            }
            else if(next.first > tickets[i][1]) {
                next.first = tickets[i][1];
                next.second = i;
            }
        }
    }
    visited[next.second] = 1;
    dfs(next.first, tickets);
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    airports = tickets.size() + 1;
    dfs("ICN", tickets);
    for(int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    return answer;
}

int main() {
    vector<string> tickets
}