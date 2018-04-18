//
//  redundant-connection-ii
//  https://leetcode.com/problems/redundant-connection-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        const int N = edges.size();
        // 找有两个父节点的节点
        vector<int> parent(N + 1, 0);
        vector<int> candA, candB;
        for (auto &edge : edges) {
            if (parent[edge[1]] == 0) {
                parent[edge[1]] = edge[0];
            } else { // 找到
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = -1; // 去掉一条父边
            }
        }
        // 并查集找环
        for (int i = 1; i <= N; i++) parent[i] = i;
        for (auto &edge : edges) {
            if (edge[1] == -1) continue; // 上一步中去掉的边
            int pu = find(edge[0], parent), pv = find(edge[1], parent);
            if (pu == pv) { // 有环
                if (!candA.empty()) return candA; // 上一步中有两个父节点的节点并去掉一条父边，却还是有环，说明去掉了错误的边
                return edge; // 不存在有两个父节点的节点，去掉新加入的导致有环的边
            }
            parent[pu] = pv; // unite
        }
        return candB; // 无环，去掉后加入的导致出现两个父节点的边
    }
    
    int find(int x, vector<int> &parent) {
        if (x != parent[x]) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
