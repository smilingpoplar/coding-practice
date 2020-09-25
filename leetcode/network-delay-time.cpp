//
//  network-delay-time
//  https://leetcode.com/problems/network-delay-time/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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

        using arr2 = array<int, 2>; // [dist, node]
        auto cmp = [](arr2 &a, arr2 &b) { 
            return a[0] > b[0]; // 最小堆
        };
        priority_queue<arr2, vector<arr2>, decltype(cmp)> pq(cmp);
        pq.push({dist[K], K});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            for (auto& [v, cost] : adj[u]) { // 遍历u的所有邻接点
                int newdist = d + cost;
                if (newdist < dist[v]) {
                    dist[v] = newdist;
                    pq.push({newdist, v}); // pq中将可能有多个v值，但后续v值对结果没影响
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
    // 若使用c++中比较函数的引用语法[&dist](){}，优先队列中可不用再存节点距离d。
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // dijkstra算法
        unordered_map<int, unordered_map<int, int>> adj;
        for (auto &e : times) {
            adj[e[0]][e[1]] = e[2];
        }
        vector<int> dist(N + 1, INT_MAX); // 节点1..N
        dist[K] = 0;

        auto cmp = [&dist](int a, int b) {
            return dist[a] > dist[a]; // 最小堆
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        pq.push(K);

        while (!pq.empty()) {
            auto u = pq.top(); pq.pop();
            for (auto& [v, cost] : adj[u]) { // 遍历u的所有邻接点
                int newdist = dist[u] + cost;
                if (newdist < dist[v]) {
                    dist[v] = newdist;
                    pq.push(v);
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
*/

/*
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Bellman-Ford算法，对所有边做N-1次松弛
        const int INF = 1e9;
        vector<int> dist(N + 1, INF);
        dist[K] = 0;
        for (int i = 1; i < N; i++) {
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
        
        // 三重循环松弛
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
