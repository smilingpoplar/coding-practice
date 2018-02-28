//
//  is-graph-bipartite
//  https://leetcode.com/problems/is-graph-bipartite/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int N = graph.size();
        vector<int> color(N, -1);
        for (int i = 0; i < N; i++) {
            if (color[i] == -1 && !dfs(i, 0, graph, color)) return false;
        }
        return true;
    }
    
    bool dfs(int node, int c, vector<vector<int>>& graph, vector<int> &color) {
        if (color[node] != -1) return color[node] == c;
        color[node] = c;
        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, 1 - c, graph, color)) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
