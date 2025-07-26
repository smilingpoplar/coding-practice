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
