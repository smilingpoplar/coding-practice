//
//  alien-dictionary
//  https://leetcode.com/problems/alien-dictionary/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> indegree;
        for (auto &word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }
        // 找相邻单词第一个不同的字母
        unordered_map<char, vector<char>> adj;
        for (int i = 0; i + 1 < words.size(); i++) {
            int minJ = min(words[i].size(), words[i+1].size());
            int j = 0;
            while (j < minJ && words[i][j] == words[i+1][j]) j++;
            if (j == minJ) continue;
            char u = words[i][j], v = words[i+1][j];
            indegree[v]++;
            adj[u].push_back(v);
        }
        // 利用入度数组的拓扑排序，实际上是bfs
        queue<char> q;
        for (auto &e : indegree) {
            if (e.second == 0) q.push(e.first);
        }
        string ans;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            ans += c;
            for (char neighbor : adj[c]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return ans.size() == indegree.size() ? ans : "";
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
