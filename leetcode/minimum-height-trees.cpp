//
//  minimum-height-trees
//  https://leetcode.com/problems/minimum-height-trees/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // 叶节点到这些“根”的距离最长，从外往内一圈圈删除叶节点，最后剩下的可作为根。
        // bfs不断删除度为1的叶节点，可能剩下1个节点或2个节点（比如一边高多1）。
        if (n == 1) return { 0 };
        
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> leaves;
        vector<int> degree(n);
        for (int i = 0; i < n; i++) {
            degree[i] = adj[i].size();
            if (degree[i] == 1) leaves.push_back(i);
        }
        
        // bfs不断删除度为1的叶节点，直到剩下1或2个节点
        while (n > 2) {
            n -= leaves.size();
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
