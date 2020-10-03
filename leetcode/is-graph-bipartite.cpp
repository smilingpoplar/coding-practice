//
//  is-graph-bipartite
//  https://leetcode.com/problems/is-graph-bipartite/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
            if (color[i] == -1 && !canColor(i, 0, graph, color)) return false;
        }
        return true;
    }
    
    bool canColor(int node, int c, vector<vector<int>> &graph, vector<int> &color) {
        if (color[node] != -1) return color[node] == c;
        color[node] = c;
        for (int neighbor : graph[node]) {
            if (!canColor(neighbor, 1 - c, graph, color)) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
