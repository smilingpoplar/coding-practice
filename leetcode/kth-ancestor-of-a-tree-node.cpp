//
//  kth-ancestor-of-a-tree-node
//  https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class TreeAncestor {
    // 记住到祖先的捷径
    // P[node][level]表示node的第2^level个祖先
    vector<vector<int>> P;
public:
    TreeAncestor(int n, vector<int>& parent) {
        P = vector<vector<int>>(n, vector<int>(20, -1));
        const int N = parent.size();
        for (int node = 0; node < N; node++) {
            P[node][0] = parent[node];
        }
        for (int node = 0; node < N; node++) {
            for (int level = 1; level < 20; level++) {
                int pNode = P[node][level-1];
                if (pNode == -1) break;
                P[node][level] = P[pNode][level-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if (node == -1) return -1;
        for (int level = 0; level < 20; level++) {
            if (k & (1 << level)) {
                node = P[node][level];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
