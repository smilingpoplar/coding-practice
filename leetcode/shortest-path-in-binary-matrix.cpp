//
//  shortest-path-in-binary-matrix
//  https://leetcode.com/problems/shortest-path-in-binary-matrix/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // 从左上角到右下角的最短路径，bfs
        if (grid[0][0] == 1) return -1;
        const int R = grid.size(), C = grid[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        using arr3 = array<int, 3>; // [dist, i, j]
        queue<arr3> q;
        q.push({1, 0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [d, r, c] = q.front();  q.pop();
            if (r == R - 1 && c == C - 1) return d;
            
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if (dr == 0 && dc == 0) continue;
                    // 遍历8个方向
                    int nr = r + dr, nc = c + dc;
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C 
                        || grid[nr][nc] || visited[nr][nc]) continue;
                    q.push({d + 1, nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
