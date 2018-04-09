//
//  number-of-distinct-islands
//  https://leetcode.com/problems/number-of-distinct-islands/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int R = grid.size();
        const int C = grid[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        set<vector<pair<int,int>>> islands; // pair:<x,y>
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] != 1 || visited[r][c]) continue;
                vector<pair<int,int>> island;
                dfs(grid, r, c, visited, island);
                normalize(island);
                islands.insert(island);
            }
        }
        return islands.size();
    }
    
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>> &visited, vector<pair<int,int>> &island) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 1 || visited[r][c]) return;
        visited[r][c] = true;
        
        island.push_back({r, c});
        
        dfs(grid, r + 1, c, visited, island); // down
        dfs(grid, r - 1, c, visited, island); // up
        dfs(grid, r, c + 1, visited, island); // right
        dfs(grid, r, c - 1, visited, island); // left
    }
    
    void normalize(vector<pair<int,int>> &island) {
        // 给island编码：将island所有坐标点排序，然后坐标转换成 到第一点的偏移
        sort(island.begin(), island.end());
        for (int i = 1; i < island.size(); i++) {
            island[i].first -= island[0].first;
            island[i].second -= island[0].second;
        }
        island[0] = {0, 0};
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
