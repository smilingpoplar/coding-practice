//
//  shortest-bridge
//  https://leetcode.com/problems/shortest-bridge/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        // dfs标记一个岛
        if (A.empty()) return 0;
        const int R = A.size(), C = A[0].size();
        vector<vector<int>> visited(R, vector<int>(C, 0));
        queue<vector<int>> q;
        bool found = false;
        for (int r = 0; r < R && !found; r++) {
            for (int c = 0; c < C; c++) {
                if (A[r][c] == 0) continue;
                dfs(r, c, A, visited, q);
                found = true;
                break;
            }
        }
        // bfs扩展这个岛（分层遍历）
        const vector<vector<int>> dirs = 
                {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int level = 0;
        while (!q.empty()) {
            for (int sz = q.size(); sz > 0; sz--) {
                auto pos = q.front();
                q.pop();
                for (auto &dir : dirs) {
                    int nr = pos[0] + dir[0], nc = pos[1] + dir[1];
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C 
                        || visited[nr][nc]) continue;
                    if (A[nr][nc] == 1) return level;
                    q.push({nr, nc}); 
                    visited[nr][nc] = true;
                }
            }
            level++;
        }
        return -1;
    }
    
    void dfs(int r, int c, vector<vector<int>>& A,
             vector<vector<int>> &visited, 
             queue<vector<int>> &q) {
        const int R = A.size(), C = A[0].size();
        if (r < 0 || r >= R || c < 0 || c >= R 
            || A[r][c] == 0 || visited[r][c]) return;
        q.push({r, c});
        visited[r][c] = true;
        
        dfs(r + 1, c, A, visited, q);
        dfs(r - 1, c, A, visited, q);
        dfs(r, c + 1, A, visited, q);
        dfs(r, c - 1, A, visited, q);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
