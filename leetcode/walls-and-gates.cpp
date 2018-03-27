//
//  walls-and-gates
//  https://leetcode.com/problems/walls-and-gates/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    const int INF = 2147483647;
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        // bfs，各门先入队
        if (rooms.empty()) return;
        const int M = rooms.size();
        const int N = rooms[0].size();
        queue<pair<int,int>> q;
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (rooms[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }
        
        const vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            int r = curr.first, c = curr.second;
            for (auto &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr < 0 || nr >= M || nc < 0 || nc >= N || rooms[nr][nc] != INF) continue;
                rooms[nr][nc] = rooms[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
