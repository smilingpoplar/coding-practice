//
//  reachable-nodes-in-subdivided-graph
//  https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>> edges, int M, int N) {
        unordered_map<int, unordered_map<int, int>> subdiv;
        for (auto &e : edges) 
            subdiv[e[0]][e[1]] = subdiv[e[1]][e[0]] = e[2];
        
        priority_queue<pair<int, int>> pq; // (剩余moves, 节点idx)
        pq.push({ M, 0 });
        unordered_map<int, int> visited; // 节点idx => 该节点剩余moves
        while (!pq.empty()) {
            auto node = pq.top(); pq.pop();
            int moves = node.first, idx = node.second;
            if (visited.count(idx)) continue;

            visited[idx] = moves;
            for (auto &e : subdiv[idx]) {
                int next = e.first, nSubdiv = e.second;
                if (visited.count(next)) continue;
                int leftMoves = moves - nSubdiv - 1;
                if (leftMoves >= 0) pq.push({ leftMoves, next });
            }
        }
        
        int ans = visited.size(); // 已到多少个节点
        for (auto &e : edges) {
            // 从某顶点e[x]出发能到visited[e[x]]个subdiv
            int a = visited.count(e[0]) ? visited[e[0]] : 0;
            int b = visited.count(e[1]) ? visited[e[1]] : 0;
            // 某条edge上最多只能到e[2]个subdiv
            ans += min(a + b, e[2]); 
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
