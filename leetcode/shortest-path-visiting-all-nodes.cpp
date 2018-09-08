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
        // 要判断是否已访问所有节点，故将所有节点的访问状态编码成二进制mask。
        // 设当前节点为curr，state=(mask,curr)是bfs的"状态节点"。
        const int N = graph.size();
        const int MASK_ALL_NODES = (1 << N) - 1;
        using State = vector<int>;
        
        queue<State> q;
        set<State> visited;
        for (int i = 0; i < N; i++) {
            State state({1 << i, i});
            q.push(state);
            visited.insert(state);
        }
        
        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto state = q.front(); q.pop();
                int mask = state[0], curr = state[1];
                if (mask == MASK_ALL_NODES) return dist;

                for (auto next : graph[curr]) {
                    State nextState({mask | (1 << next), next});
                    if (visited.count(nextState)) continue;
                    q.push(nextState);
                    visited.insert(nextState);
                }
            }
            dist++;
        }
        return dist;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
