//
//  possible-bipartition
//  https://leetcode.com/problems/possible-bipartition/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
        
        vector<int> color(N + 1, -1);
        for (int i = 1; i <= N; i++) {
            if (color[i] == -1 && !canColor(i, 0, adj, color)) return false;
        }
        return true;
    }
    
    bool canColor(int idx, int c, vector<unordered_set<int>> &adj, vector<int> &color) {
        if (color[idx] != -1) return color[idx] == c;
        
        color[idx] = c;
        for (auto &next : adj[idx]) {
            if (!canColor(next, 1 - c, adj, color)) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
