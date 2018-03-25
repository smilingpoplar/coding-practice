//
//  cheapest-flights-within-k-stops
//  https://leetcode.com/problems/cheapest-flights-within-k-stops/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // 不是dijkstra算法。dijkstra只考虑到当前点的最短路径，不考虑更长路径，但这里不行。
        // 当前点的最短路径可能因为K步的限制不能成为最终点的最短路径，所以要考虑K步内的所有路径。
        if (flights.empty()) return -1;
        const int M = flights.size();
        const int N = flights[0].size();
        unordered_map<int, unordered_map<int, int>> adj;
        for (auto &e : flights) {
            adj[e[0]][e[1]] = e[2];
        }
        
        auto cmp = [](vector<int> &a, vector<int> &b) { // {node, dist, steps}
            return a[1] > b[1]; // 最小堆
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({src, 0, 0});
        while (!pq.empty()) {
            auto info = pq.top(); pq.pop();
            int curr = info[0], dist = info[1], step = info[2];
            if (curr == dst) return dist;
            
            for (auto &e : adj[curr]) {
                int next = e.first, cost = e.second;
                if (step < K + 1) { // K个中间站，即可往外走K+1步
                    pq.push({next, dist + cost, step + 1});
                }
            }
        }
        return -1;
    }
};
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // bellman ford算法，对所有边做K+1次松弛
        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[src] = 0;
        for (int i = 0; i <= K; i++) {
            auto prev = dist;
            for (auto &e : flights) {
                int u = e[0], v = e[1], cost = e[2];
                dist[v] = min(dist[v], prev[u] + cost);
            }
        }
        return (dist[dst] != INF) ? dist[dst] : -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
