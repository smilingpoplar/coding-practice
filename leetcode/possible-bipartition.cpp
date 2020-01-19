//
//  possible-bipartition
//  https://leetcode.com/problems/possible-bipartition/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<unordered_set<int>> adj(N + 1);
        for (auto &e : dislikes) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        
        vector<int> colors(N + 1, -1);
        for (int i = 1; i <= N; i++) {
            if (colors[i] == -1 && !canColor(i, 0, adj, colors)) return false;
        }
        return true;
    }
    
    bool canColor(int idx, int color, vector<unordered_set<int>> &adj, vector<int> &colors) {
        if (colors[idx] != -1) return colors[idx] == color;
        
        colors[idx] = color;
        for (auto &next : adj[idx]) {
            if (!canColor(next, 1 - color, adj, colors)) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
