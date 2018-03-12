//
//  shortest-distance-from-all-buildings
//  https://leetcode.com/problems/shortest-distance-from-all-buildings/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        // 对每个1点bfs找出它到0点的距离，并把这个距离*累加*到0点的dist[r][c]中，
        // 这样所有1点做完bfs后，某0点的dist[r][c]是该0点到所有*可达*1点的距离和。
        // 还要有个reach[r][c]记录几个1点可达该0点。
        // 最终要找reach[r][c]==buildingCount的0点中dist[r][c]最小的。
        if (grid.empty()) return 0;
        const int M = grid.size();
        const int N = grid[0].size();
        int buildingCount = 0;
        vector<vector<int>> dist(M, vector<int>(N, 0));
        vector<vector<int>> reach(M, vector<int>(N, 0));
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] == 1) {
                    buildingCount++;
                    bfs(r, c, grid, dist, reach);
                }
            }
        }

        int shortest = INT_MAX;
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] == 0 && reach[r][c] == buildingCount) {
                    shortest = min(shortest, dist[r][c]);
                }
            }
        }
        return shortest != INT_MAX ? shortest : -1;
    }
    
    void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dist, vector<vector<int>> &reach) {
        const int M = grid.size();
        const int N = grid[0].size();
        const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        queue<pair<int, int>> q;
        q.push({row, col});

        int level = 0;
        while (!q.empty()) {
            level++;
            for (int levelSize = q.size(); levelSize > 0; levelSize--) {
                auto curr = q.front(); q.pop();
                for (auto &dir : dirs) {
                    int r = curr.first + dir[0], c = curr.second + dir[1];
                    if (r < 0 || r >= M || c < 0 || c >= N || grid[r][c] != 0 || visited[r][c]) continue;
                    
                    visited[r][c] = true;
                    dist[r][c] += level;
                    reach[r][c]++;                    
                    q.push({r, c});
                }                
            }
        }        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
