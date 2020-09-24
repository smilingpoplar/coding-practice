//
//  swim-in-rising-water
//  https://leetcode.com/problems/swim-in-rising-water/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // 最少时间到达右下角，等价于到右下角时水面要最低，因此
        // 用优先队列的图遍历（dijkstra算法），海拔高度小的优先
        if (grid.empty()) return 0;
        const int R = grid.size(), C = grid[0].size();
        // 优先队列存坐标{i,j}
        auto cmp = [&grid](const vector<int> &idx1, const vector<int> &idx2) {
            return grid[idx1[0]][idx1[1]] > grid[idx2[0]][idx2[1]]; // 最小堆
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        const vector<vector<int>> dirs = { {0,-1}, {-1,0}, {0,1}, {1,0} };
        
        int ans = 0;
        visited[0][0] = true;
        pq.push({0,0});
        while (!pq.empty()) {
            auto curr = pq.top();  pq.pop();
            int r = curr[0], c = curr[1];
            ans = max(ans, grid[r][c]);
            if (r == R - 1 && c == C - 1) return ans;

            for (auto &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
                visited[nr][nc] = true;
                pq.push({nr, nc});
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
