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
        vector<int> colors(N, -1);
        for (int i = 0; i < N; i++) {
            if (colors[i] == -1 && !canColor(i, 0, graph, colors)) return false;
        }
        return true;
    }
    
    bool canColor(int node, int c, vector<vector<int>> &graph, vector<int> &colors) {
        if (colors[node] != -1) return colors[node] == c;
        colors[node] = c;
        for (int neighbor : graph[node]) {
            if (!canColor(neighbor, 1 - c, graph, colors)) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
