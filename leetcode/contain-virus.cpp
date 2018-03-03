//
//  contain-virus
//  https://leetcode.com/problems/contain-virus/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    struct Area {
        set<pair<int,int>> ones; // 1的坐标
        set<pair<int,int>> neighbors; // 邻居0的坐标
        int walls = 0; // 需要多少墙隔离该区域
    };
public:
    int containVirus(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int M = grid.size();
        const int N = grid[0].size();
        
        int walls = 0;
        while (true) {
            // 找出各个区域
            vector<vector<bool>> visited(M, vector<bool>(N, false));
            vector<Area> areas;
            for (int r = 0; r < M; r++) {
                for (int c = 0; c < N; c++) {
                    if (!visited[r][c] && grid[r][c] == 1) {
                        Area area;
                        dfs(r, c, grid, visited, area);
                        areas.push_back(area);
                    }
                }
            }
            if (areas.empty()) break;
            // 找可感染邻居最多的区域
            int idx = 0;
            for (int i = 1; i < areas.size(); i++) {
                if (areas[i].neighbors.size() > areas[idx].neighbors.size()) {
                    idx = i;
                }
            }
            // 保护这片区域，将grid[r][c]设为-1
            for (auto &rc : areas[idx].ones) {
                grid[rc.first][rc.second] = -1;
            }
            walls += areas[idx].walls;
            // 其他区域，将邻居感染
            for (int i = 0; i < areas.size(); i++) {
                if (i == idx) continue;
                for (auto &rc : areas[i].neighbors) {
                    grid[rc.first][rc.second] = 1;
                }
            }
        }
        return walls;
    }
    
    // 找1的连通区域，同时找出它的邻居0们，以及和邻居0的间隔数
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>> &visited, Area &area) {
        if (visited[r][c] || grid[r][c] != 1) return;
        visited[r][c] = true;
        area.ones.insert({r, c});

        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (auto &dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];
            if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()) continue;
            if (grid[nr][nc] == 1) {
                dfs(nr, nc, grid, visited, area);
            } else if (grid[nr][nc] == 0) {
                area.neighbors.insert({nr, nc});
                area.walls++;
            } 
            // 已被墙保护的grid[r][c]==-1，不用处理
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
