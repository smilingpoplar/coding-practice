//
//  redundant-connection
//  https://leetcode.com/problems/redundant-connection/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 并查集
        const int N = edges.size();
        vector<int> parent(N + 1, 0);
        for (int i = 1; i <= N; i++) parent[i] = i;
        // unite
        for (auto &edge : edges) {
            int pu = find(edge[0], parent);
            int pv = find(edge[1], parent);
            if (pu == pv) return edge;
            parent[pu] = pv;
        }
        return {};
    }
    
    int find(int x, vector<int> &parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
