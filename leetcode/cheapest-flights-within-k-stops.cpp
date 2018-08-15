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
        // K个中间站，即可往外走K+1步
        // 不是dijkstra算法，dijkstra的最小代价路径可能超过K+1步不能被选、而且K+1步内代价更大的路径没被考虑
        // 修改dijkstra，这里要考虑K+1步内的所有路径
        if (flights.empty()) return -1;
        const int M = flights.size(), N = flights[0].size();
        unordered_map<int, unordered_map<int, int>> adj;
        for (auto &e : flights) {
            adj[e[0]][e[1]] = e[2];
        }
        
        auto cmp = [](vector<int> &a, vector<int> &b) { // {node, dist, step}
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
                if (step < K + 1) { // 走K+1步
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
        // 从src到dst最多K个中间站，共V=K+2个节点
        // bellman ford算法，对所有边做V-1=K+1次松弛
        const int INF = 1e9;
        vector<int> dist(n, INF); // src到各节点的距离
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
