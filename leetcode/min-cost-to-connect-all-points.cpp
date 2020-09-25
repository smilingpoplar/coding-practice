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
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push({cost, i, j});
            }
        }

        int ans = 0, cnt = 0;
        while (!pq.empty()) {
            const auto [cost, x, y] = pq.top(); pq.pop();
            // unite
            int px = find(x, uf), py = find(y, uf);
            if (px != py) {
                uf[py] = px;
                ans += cost;
                if (++cnt == N - 1) break; // N个节点最多N-1条边
            }
        }
        return ans;
    }

    int find(int x, vector<int> &uf) {
        if (uf[x] != x) uf[x] = find(uf[x], uf);
        return uf[x];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
