//
//  swim-in-rising-water
//  https://leetcode.com/problems/swim-in-rising-water/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // 用优先队列的图遍历（dijkstra算法），用海拔高度小的优先
        if (grid.empty()) return 0;
        const int M = grid.size();
        const int N = grid[0].size();
        // 优先队列存坐标{i,j}
        auto cmp = [&grid](const vector<int> &idx1, const vector<int> &idx2) {
            return grid[idx1[0]][idx1[1]] > grid[idx2[0]][idx2[1]];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        const vector<vector<int>> dirs = { {0,-1},{1,0},{0,1},{-1,0} };
        
        int ans = 0;
        pq.push({0,0});
        visited[0][0] = true;
        while (!pq.empty()) {
            auto top = pq.top();  pq.pop();
            int r = top[0], c = top[1];
            ans = max(ans, grid[r][c]);
            if (r == M - 1 && c == N - 1) return ans;

            for (auto &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr < 0 || nr >= M || nc < 0 || nc >= N || visited[nr][nc]) continue;
                pq.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
