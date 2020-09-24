//
//  redundant-connection-ii
//  https://leetcode.com/problems/redundant-connection-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // 两种可并存的情况：
        // 冗余边指向非根节点 => 该节点有两个父节点
        //      指向祖父节点 => 有环
        //
        // 先找有两个父节点的节点，找到时把两条父边作为冗余候选，从图中去掉一条。
        // 再在“没有两个父节点的节点”的图上用并查集找环，边的两端属于同一集合时有环。
        // 1. 若这一步有环，上一步有候选，冗余边是 保留的候选边
        // 2.        有        无             并查集中刚导致有环的边
        // 3.        无        有             去掉的侯选边
        const int N = edges.size();
        vector<int> parent(N + 1, 0); // 节点是1-based
        vector<int> candA, candB;
        for (auto &edge : edges) {
            if (parent[edge[1]] == 0) {
                parent[edge[1]] = edge[0];
            } else { // edge[1]有两个父节点，把两条父边作为冗余候选
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = -1; // 从图中去掉candB
            }
        }
        // 并查集找环
        for (int i = 1; i <= N; i++) parent[i] = i;
        for (auto &edge : edges) {
            if (edge[1] == -1) continue; // 上一步中去掉的边
            int pu = find(edge[0], parent), pv = find(edge[1], parent);
            if (pu == pv) { // 有环
                if (!candA.empty()) return candA; // case 1
                return edge; // case 2
            }
            parent[pu] = pv; // unite
        }
        return candB; // case 3
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
