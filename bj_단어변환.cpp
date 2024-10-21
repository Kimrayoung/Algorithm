#include <bits/stdc++.h> 
using namespace std;
int visited[54], ret = 987654321;

void dfs(string word, vector<string> &words, int temp, string target) {
    if(word == target) {
        ret = min(ret, temp);
        return;
    };
    
    for(int i = 0; i < words.size(); i++) {
        if(visited[i]) continue;
        int diff = 0;
        for(size_t j = 0; j < word.length(); j++) {
            if(word[j] != words[i][j]) diff++;
            if(diff > 1) break;
        }
        if(diff == 1) {
            visited[i] = 1;
            temp++;
            dfs(words[i], words, temp, target);
            temp--;
            visited[i] = 0;
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, words, 0, target);
    
    return ret == 987654321 ? 0 : ret;
}