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
        // 两种可并存的情况：
        // 冗余边指向非根节点 => 该节点有两个父节点
        //      指向祖父节点 => 有环
        //
        // 先找有两个父节点的节点，找到的话把两条父边作为冗余候选，从图中去掉其中一条。
        // 再用并查集找环，若新边的两端已同属一个集合则有环。
        // 若上一步有候选，这一步还有环，说明冗余边是保留的候选边；
        //        无           有              后加入的导致有环的边；
        //        有           无              去掉的侯选边。
        const int N = edges.size();
        vector<int> parent(N + 1, 0);
        vector<int> candA, candB;
        for (auto &edge : edges) {
            if (parent[edge[1]] == 0) {
                parent[edge[1]] = edge[0];
            } else { // 有两个父节点，将两条父边作为冗余候选
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
                if (!candA.empty()) return candA; // 有候选
                return edge; // 无候选
            }
            parent[pu] = pv; // unite
        }
        return candB; // 无环
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
