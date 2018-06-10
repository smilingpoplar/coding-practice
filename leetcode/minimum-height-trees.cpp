//
//  minimum-height-trees
//  https://leetcode.com/problems/minimum-height-trees/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return { 0 };
        
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        vector<int> degree(n);
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            degree[i] = adj[i].size();
            if (degree[i] == 1) leaves.push_back(i);
        }
        
        // bfs不断删除度为1的叶节点，直到剩下1或2个节点
        int remain = n;
        while (remain > 2) {
            remain -= leaves.size();
            vector<int> newLeaves;
            for (int u : leaves) {
                for (int v : adj[u]) {
                    if (--degree[v] == 1) newLeaves.push_back(v);
                }
            }
            swap(leaves, newLeaves);
        }
        return leaves;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
