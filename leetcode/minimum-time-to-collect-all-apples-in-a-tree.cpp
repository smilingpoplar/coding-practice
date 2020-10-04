//
//  minimum-time-to-collect-all-apples-in-a-tree
//  https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for (const auto & edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        // 返回摘完子树苹果（不含根），要花的最少时间
        function<int(int)> dfs = [&](int u) {
            int ans = 0;
            for (auto v : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    int sub = dfs(v);
                    if (sub > 0 || hasApple[v]) 
                        ans += 2 + sub;
                }
            }
            return ans;
        };
        
        visited[0] = true;
        return dfs(0);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
