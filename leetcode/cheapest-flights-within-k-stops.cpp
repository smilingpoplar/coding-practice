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

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // dijkstra算法，抛掉steps>K的情况
        if (flights.empty()) return -1;
        const int M = flights.size();
        const int N = flights[0].size();
        unordered_map<int, unordered_map<int, int>> adj;
        for (auto &e : flights) {
            adj[e[0]][e[1]] = e[2];
        }
        vector<int> dists(n, INT_MAX);
        dists[src] = 0;
        
        auto cmp = [](vector<int> &a, vector<int> &b) { // {node, dist, steps}
            return a[1] > b[0]; // 最小堆
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({src, dists[src], 0});
        while (!pq.empty()) {
            auto info = pq.top(); pq.pop();
            int u = info[0], dist = info[1], step = info[2];
            if (step > K) continue;
            for (auto &neighbor : adj[u]) {
                int v = neighbor.first, cost = neighbor.second;
                int newdist = dist + cost;
                if (newdist < dists[v]) {
                    dists[v] = newdist;
                    pq.push({v, newdist, step + 1});
                }
            }
        }
        return (dists[dst] != INT_MAX) ? dists[dst] : -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
