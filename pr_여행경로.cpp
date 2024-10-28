#include <bits/stdc++.h>

using namespace std;
vector<string> ret;
int visited[10000000], airports;
bool flag;

void dfs(string start, vector<vector<string>>& tickets) {
    if (ret.size() == airports) {
        flag = 1;
        return;
    }
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
    ret.push_back(next.first);
    dfs(next.first, tickets);
    if(!flag) {
        visited[next.second] = 0;
        ret.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    airports = tickets.size() + 1;
    ret.push_back("ICN");
    dfs("ICN", tickets);
    // for(int i = 0; i < ret.size(); i++) {
    //     cout << ret[i] << " ";
    // }
    return ret;
}

// #include <bits/stdc++.h>

// using namespace std;
// vector<string> ret;
// vector<vector<string>> sortTickets;
// int visited[10000000], airports;
// bool flag;

// void dfs(string start, int cnt) {
//     ret.push_back(start);
//     if(cnt == airports) flag = true;
//     for(int i = 0; i < sortTickets.size(); i++) {
//         if(!visited[i] && sortTickets[i][0] == start) {
//             visited[i] = 1;
//             cnt++;
//             dfs(sortTickets[i][1], cnt);
//             // 만약에 제시된 공항을 모두 돌았다면 
//             if(!flag) {
//                 ret.pop_back();
//                 visited[i] = false;
//             }
//         }
//     }
// }

// vector<string> solution(vector<vector<string>> tickets) {
//     vector<string> answer;
//     sort(tickets.begin(), tickets.end());
//     sortTickets = tickets;
//     airports = tickets.size() + 1;
//     ret.push_back("ICN");
//     dfs("ICN");

//     return ret;
// }