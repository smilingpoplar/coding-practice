//
//  bricks-falling-when-hit
//  https://leetcode.com/problems/bricks-falling-when-hit/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    class UnionFind {
        vector<int> parent;
        vector<int> size;        
    public:
        UnionFind(int sz) : parent(sz), size(sz, 1) { 
            for (int i = 0; i < sz; i++)
                parent[i] = i;
        }
        
        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        
        void unite(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;
            
            if (size[px] < size[py]) swap(px, py);
            size[px] += size[py];
            parent[py] = px;
        }
        
        int topBricksCount() { // 与"顶部"相连的砖块数
            return size[find(parent.size() - 1)] - 1;
        }
    };
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        // 把时间反转，从hits[]全应用的局面开始，一步步恢复被消除的砖块，
        // 看与"顶部"相连的砖块数的变化
        if (grid.empty()) return {};
        const int R = grid.size(), C = grid[0].size();
        vector<vector<int>> erased(grid);
        for (auto &hit : hits) { // 先是hits[]全应用的局面
            erased[hit[0]][hit[1]] = 0;
        }
        UnionFind uf(R * C + 1); // idx=R*C是特殊的"顶部"节点
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (!erased[r][c]) continue;
                int idx = r * C + c;
                // idx与上下左右连接（连接就是并查集unite）
                // 从上往下、从左往右遍历，只要考虑与上左的连接
                if (r == 0) uf.unite(idx, R * C); // 首行砖块与"顶部"连接
                if (r > 0 && erased[r-1][c]) uf.unite(idx, (r - 1) * C + c);
                if (c > 0 && erased[r][c-1]) uf.unite(idx, r * C + (c - 1));
            }
        }
        int prev = uf.topBricksCount();
        
        const int N = hits.size();
        vector<int> ans(N, 0);
        vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        // 一步步恢复被消除的砖块
        for (int i = N - 1; i >= 0; i--) {
            int r = hits[i][0], c = hits[i][1];
            if (!grid[r][c]) continue;
            erased[r][c] = 1;
            int idx = r * C + c;
            // 让idx与上下左右连接
            if (r == 0) uf.unite(idx, R * C);
            for (auto &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (0 <= nr && nr < R && 0 <= nc && nc < C && erased[nr][nc]) {
                    uf.unite(idx, nr * C + nc);
                }
            }
            int curr = uf.topBricksCount();
            // 若curr>prev，掉落curr-prev-1块；若curr==prev，掉落0块          
            ans[i] = max(curr - prev - 1, 0);
            prev = curr;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
