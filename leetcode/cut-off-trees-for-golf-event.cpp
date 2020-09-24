//
//  cut-off-trees-for-golf-event
//  https://leetcode.com/problems/cut-off-trees-for-golf-event/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty()) return 0;
        const int R = forest.size();
        const int C = forest[0].size();
        vector<vector<int>> indices;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (forest[r][c] > 0) 
                    indices.push_back({r, c});
            }
        }
        sort(indices.begin(), indices.end(), [&forest](const vector<int> &a, const vector<int> &b) {
            return forest[a[0]][a[1]] < forest[b[0]][b[1]];
        });
        
        int ans = 0;
        int r = 0, c = 0;
        for (auto &idx : indices) {
            int d = dist(r, c, idx[0], idx[1], forest);
            if (d == -1) return -1;
            ans += d;
            r = idx[0], c = idx[1];
        }
        return ans;
    }
    
    int dist(int sr, int sc, int tr, int tc, vector<vector<int>>& forest) {
        // bst求最短距离
        const int R = forest.size();
        const int C = forest[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;

        int ans = 0;
        while (!q.empty()) {
            for (int n = q.size(); n > 0; n--) {
                auto node = q.front(); q.pop();
                int r = node.first, c = node.second;
                if (r == tr && c == tc) return ans;
                
                for (auto &dir : dirs) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc] || forest[nr][nc] == 0) continue;
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
            ans++;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
