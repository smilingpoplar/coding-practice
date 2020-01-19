//
//  shortest-path-visiting-all-nodes
//  https://leetcode.com/problems/shortest-path-visiting-all-nodes/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // 为判断是否已访问所有节点，将所有节点的访问状态编码成二进制mask
        // 设当前节点编号curr，bfs的"状态节点"为 (mask,curr)
        const int N = graph.size();
        const int MASK_TARGET = (1 << N) - 1;

        vector<vector<bool>> visited(1 << N, vector<bool>(N, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < N; i++) {
            q.push({1 << i, i});
        }

        int dist = 0;
        while (!q.empty()) {
            for (int sz = q.size(); sz > 0; sz--) {
                auto state = q.front(); q.pop();                
                int mask = state.first, curr = state.second;
                if (visited[mask][curr]) continue;
                visited[mask][curr] = true;

                if (mask == MASK_TARGET) return dist;
                for (auto next : graph[curr]) {
                    q.push({mask | (1 << next), next});
                }
            }
            dist++;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
