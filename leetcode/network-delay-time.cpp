//
//  network-delay-time
//  https://leetcode.com/problems/network-delay-time/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        map<int, map<int, int>> adj;
        for (auto &e : times) {
            adj[e[0]][e[1]] = e[2];
        }
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        
        // vector<int> visited(N + 1, false);
        auto cmp = [&dist](int i, int j) {
            return dist[i] > dist[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        pq.push(K);
        while (!pq.empty()) {
            int u = pq.top(); pq.pop();
            // if (visited[u]) continue;
            // visited[u] = true;
            for (auto &e : adj[u]) { // 遍历u的所有邻接点
                int v = e.first;
                int newdist = dist[u] + e.second;
                if (newdist < dist[v]) {
                    dist[v] = newdist;
                    pq.push(v); // pq中将可能有多个v值，但后续v值对结果没影响。可用visited[]来排除。
                }
            }
        }
        
        int ans = INT_MIN;
        for (int i = 1; i < dist.size(); i++) {
            ans = max(ans, dist[i]);
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
