//
//  mini-spanning-tree
//  NC159 最小生成树
//

#include <iostream>

using namespace std;

class Solution {
public:
    int miniSpanningTree(int n, int m, vector<vector<int> >& cost) {
        // Kruskal法，并查集+优先队列
        sort(begin(cost), end(cost),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });
        vector<int> uf(n + 1, -1);  // 顶点是1-based编号
        for (int i = 0; i <= n; i++) {
            uf[i] = i;
        }

        int ans = 0;
        for (auto& e : cost) {
            int x = find(e[0], uf), y = find(e[1], uf);
            if (x != y) {  // 两点不相连
                uf[x] = y;
                ans += e[2];
            }
        }
        return ans;
    }

    int find(int x, vector<int>& uf) {
        if (uf[x] != x) {
            uf[x] = find(uf[x], uf);
        }
        return uf[x];
    }
};

/*
#include <climits>
#include <queue>

class Solution {
  public:
    int miniSpanningTree(int n, int m, vector<vector<int> >& cost) {
        // Prim算法，图遍历+优先队列
        vector<int> dist(n + 1, INT_MAX); // 各节点到MST的距离
        dist[1] = 0; // 节点是1-based编号

        // 邻接表
        unordered_map<int, unordered_map<int, int>> adj;
        for (auto &e : cost) {
            // 多条路径选最小的那条
            int u = e[0], v = e[1], d = e[2];
            if (!adj[u].count(v) || d < adj[u][v])
                adj[u][v] = d;
            if (!adj[v].count(u) || d < adj[v][u])
                adj[v][u] = d;
        }
        // 优先队列
        auto cmp = [](const vector<int>& a, const vector<int>& b) { // [dist, from]
            return a[0] > b[0]; // 最小堆
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({dist[1], 1});

        int ans = 0, cnt = 0;
        vector<int> seen(n + 1, false);
        while (!pq.empty() && cnt < n) { // MST有n个顶点
            auto top = pq.top(); pq.pop();
            int d = top[0], u = top[1]; // MST中的顶点
            if (seen[u]) continue;
            seen[u] = true;
            ans += d;
            cnt++;

            for (int v = 1; v <= n; v++) {
                if (seen[v] || !adj[u].count(v)) continue;
                int newdist = adj[u][v];
                if (newdist < dist[v]) {
                    dist[v] = newdist;
                    pq.push({newdist, v});
                }
            }
        }
        return ans;
    }
};
*/
