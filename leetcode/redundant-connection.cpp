//
//  redundant-connection
//  https://leetcode.com/problems/redundant-connection/
//
//  Created by smilingpoplar on 18/01/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class DisjoinSetUnion {
    vector<int> parent;
    vector<int> rank;
public:
    DisjoinSetUnion(int N) : parent(N+1), rank(N+1, 0) {
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[py] < rank[px]) {
            parent[py] = px;
        } else {
            parent[px] = py;
            ++rank[py];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int N = edges.size();
        DisjoinSetUnion dsu(N);
        for (auto &edge : edges) {
            if (!dsu.merge(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
