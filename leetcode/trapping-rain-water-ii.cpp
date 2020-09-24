//
//  trapping-rain-water-ii
//  https://leetcode.com/problems/trapping-rain-water-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // 可视化解释：https://www.youtube.com/watch?v=cJayBq38VYw
        // 用优先队列的遍历算法
        if (heightMap.empty()) return 0;
        const int R = heightMap.size(), C = heightMap[0].size();
        // 队列元素int[3]: { row, col, heightWithWater }
        auto cmp = [](vector<int> &a, vector<int> &b) {
            return a[2] > b[2]; // 高度最小的先出队处理
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        // 四条边先入队
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (r == 0 || r == R - 1 || c == 0 || c == C - 1) {
                    pq.push({r, c, heightMap[r][c]});
                    visited[r][c] = true;
                }
            }
        }
        
        int ans = 0;
        vector<vector<int>> dirs = { {-1,0}, {0,1}, {1,0}, {0,-1} };
        while (!pq.empty()) {
            auto elem = pq.top();  pq.pop();
            int r = elem[0], c = elem[1], heightWithWater = elem[2];
            
            for (auto &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
                // 若邻居的高度更小，该邻居柱上可储水，储水量为高度差
                int diff = heightWithWater - heightMap[nr][nc];
                if (diff > 0) ans += diff;
                pq.push({nr, nc, max(heightWithWater, heightMap[nr][nc])});
                visited[nr][nc] = true;
            }            
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
