//
//  shortest-path-with-alternating-colors
//  https://leetcode.com/problems/shortest-path-with-alternating-colors/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        // color: 0 red, 1 blud
        vector<unordered_map<int, vector<int>>> graph(2);
        for (auto &red : red_edges) {
            graph[0][red[0]].push_back(red[1]);
        }
        for (auto &blue : blue_edges) {
            graph[1][blue[0]].push_back(blue[1]);
        }
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        
        vector<int> ans(n, -1);
        queue<vector<int>> q;
        q.push({0, 0, 0});
        q.push({0, 1, 0});
        while (!q.empty()) {
            auto info = q.front(); q.pop();
            int u = info[0], color = info[1], dist = info[2];
            if (visited[color][u]) continue;
            visited[color][u] = true;
            if (ans[u] == -1) ans[u] = dist;

            for (int v : graph[color][u]) {
                q.push({v, 1 - color, dist + 1});
            }
        }
        return ans;
    }    
};

int main(int argc, const char * argv[]) {    
    return 0;
}
