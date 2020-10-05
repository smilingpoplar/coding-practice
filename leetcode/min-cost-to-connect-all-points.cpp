//
//  min-cost-to-connect-all-points
//  https://leetcode.com/problems/min-cost-to-connect-all-points/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 最小生成树的Kruskal算法，并查集+优先队列
        // 完全连接E=O(N^2)，所以O(ElgE)=O(N^2*2N)=O(N^3)
        const int N = points.size();
        vector<int> uf(N); 
        for (int i = 0; i < N; i++) {
            uf[i] = i;
        }

        using arr3 = array<int, 3>;
        auto cmp = [](arr3 &a, arr3 &b) {
            return a[0] > b[0]; // 最小堆
        };        
        priority_queue<arr3, vector<arr3>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int cost = distance(i, j, points);
                pq.push({cost, i, j});
            }
        }

        int ans = 0, cnt = 0;
        while (!pq.empty() && cnt != N - 1) {
            const auto [cost, x, y] = pq.top(); pq.pop();
            // unite
            int px = find(x, uf), py = find(y, uf);
            if (px != py) {
                uf[py] = px;
                ans += cost;
                cnt++;
            }
        }
        return ans;
    }

    int find(int x, vector<int> &uf) {
        if (uf[x] != x) uf[x] = find(uf[x], uf);
        return uf[x];
    }

    int distance(int u, int v, vector<vector<int>> &points) {
        auto &pu = points[u], &pv = points[v];
        return abs(pu[0] - pv[0]) + abs(pu[1] - pv[1]);
    }
};

/*
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 最小生成树的Prim算法，图遍历+优先队列
        // O(N^2)
        const int N = points.size();
        vector<int> dist(N, INT_MAX); // 各节点到最小生成树的距离
        dist[0] = 0;

        using arr2 = array<int, 2>; // [dist, idx]
        auto cmp = [](arr2 &a, arr2 &b) {
            return a[0] > b[0]; // 最小堆
        };
        priority_queue<arr2, vector<arr2>, decltype(cmp)> pq(cmp);
        pq.push({dist[0], 0});

        int ans = 0;
        vector<int> visited(N, false);
        while (!pq.empty()) {
            auto [d, u] = pq.top();  pq.pop();
            if (visited[u]) continue;
            visited[u] = true;
            ans += d;

            for (int v = 0; v < N; v++) {
                if (visited[v]) continue;
                int newdist = distance(u, v, points);
                if (newdist < dist[v]) {
                    dist[v] = newdist;
                    pq.push({newdist, v});
                }
            }
        }
        return ans;
    }

    int distance(int u, int v, vector<vector<int>> &points) {
        auto &pu = points[u], &pv = points[v];
        return abs(pu[0] - pv[0]) + abs(pu[1] - pv[1]);
    }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
