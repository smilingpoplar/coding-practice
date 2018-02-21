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
        // dijkstra算法，抛掉step>K的情况
        if (flights.empty()) return -1;
        const int M = flights.size();
        const int N = flights[0].size();
        unordered_map<int, unordered_map<int, int>> adj;
        for (auto &e : flights) {
            adj[e[0]][e[1]] = e[2];
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        auto cmp = [](vector<int> &a, vector<int> &b) { // {node, dist, steps}
            return a[1] > b[0]; // 最小堆
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({src, dist[src], 0});
        while (!pq.empty()) {
            auto info = pq.top(); pq.pop();
            int u = info[0], d = info[1], step = info[2];
            if (step > K) continue;
            for (auto &neighbor : adj[u]) {
                int v = neighbor.first, cost = neighbor.second;
                int newdist = d + cost;
                if (newdist < dist[v]) {
                    dist[v] = newdist;
                    pq.push({v, newdist, step + 1});
                }
            }
        }
        return (dist[dst] != INT_MAX) ? dist[dst] : -1;
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
                int newdist = prev[u] + cost;
                if (newdist < dist[v]) dist[v] = newdist;
            }
        }
        return (dist[dst] != INF) ? dist[dst] : -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
