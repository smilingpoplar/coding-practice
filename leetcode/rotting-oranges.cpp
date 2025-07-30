//
//  rotting-oranges
//  https://leetcode.com/problems/rotting-oranges/
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int R = grid.size(), C = grid[0].size();
        queue<vector<int>> q;
        int fresh = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0) return 0;

        int minutes = 0;
        while (!q.empty()) {
            minutes++;
            for (int sz = q.size(); sz > 0; sz--) {
                auto rc = q.front();
                q.pop();
                int r = rc[0], c = rc[1];

                vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C ||
                        grid[nr][nc] != 1) continue;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    if (--fresh == 0) {
                        return minutes;
                    }
                }
            }
        }
        return (fresh > 0) ? -1 : minutes;
    }
};
