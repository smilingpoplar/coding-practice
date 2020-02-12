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
        // dijkstra算法
        unordered_map<int, unordered_map<int, int>> adj;
        for (auto &e : times) {
            adj[e[0]][e[1]] = e[2];
        }
        vector<int> dist(N + 1, INT_MAX); // 节点1..N
        dist[K] = 0;
        
        auto cmp = [](vector<int> &a, vector<int> &b) { // {node, dist}
            return a[1] > b[1]; // 最小堆
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({K, dist[K]});
        
        while (!pq.empty()) {
            auto info = pq.top(); pq.pop();
            int u = info[0], d = info[1];
            for (auto &e : adj[u]) { // 遍历u的所有邻接点
                int v = e.first, cost = e.second;

                int newdist = d + cost;
                if (newdist < dist[v]) {
                    dist[v] = newdist;
                    pq.push({v, newdist}); // pq中将可能有多个v值，但后续v值对结果没影响
                }
            }
        }
        
        int ans = INT_MIN;
        for (int i = 1; i <= N; i++) {
            ans = max(ans, dist[i]);
        }
        return (ans != INT_MAX) ? ans : -1;
    }
};

/*
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Bellman-Ford算法，对所有边做N-1次松弛
        const int INF = 1e9;
        vector<int> dist(N + 1, INF);
        dist[K] = 0;
        for (int i = 0; i < N; i++) {
            auto prev = dist;
            for (auto &e : times) {
                int u = e[0], v = e[1], cost = e[2];
                dist[v] = min(dist[v], prev[u] + cost);
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= N; i++) {
            ans = max(ans, dist[i]);
        }
        return (ans != INF) ? ans : -1;
    }
};
 */

/*
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Floyd算法，所有点对的最短路径
        const int INF = 1e9;
        vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
        for (int i = 1; i <= N; i++) {
            dist[i][i] = 0;
        }
        for (auto &e : times) {
            dist[e[0]][e[1]] = e[2];
        }
        
        // 三重循环做松弛
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    int newdist = dist[i][k] + dist[k][j];
                    if (newdist < dist[i][j]) {
                        dist[i][j] = newdist;
                    }
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= N; i++) {
            ans = max(ans, dist[K][i]);
        }
        return (ans != INF) ? ans : -1;
    }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
