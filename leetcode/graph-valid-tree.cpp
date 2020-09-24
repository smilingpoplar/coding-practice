//
//  graph-valid-tree
//  https://leetcode.com/problems/graph-valid-tree/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1) return false;
        // 用并查集
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        // 每条边应该连接不同集合中的点
        for (auto &edge : edges) {
            int x = find(edge.first, parent);
            int y = find(edge.second, parent);
            if (x == y) return false;
            parent[x] = y;
        }
        return true;
    }
    
    int find(int x, vector<int> &parent) {
        if (parent[x] != x) 
            parent[x] = find(parent[x], parent);
        return parent[x];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
