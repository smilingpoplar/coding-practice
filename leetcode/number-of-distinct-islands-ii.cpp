//
//  number-of-distinct-islands-ii
//  https://leetcode.com/problems/number-of-distinct-islands-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
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
        // 1. 旋转和翻转共8种坐标变换：{x,y}, {x,-y}, {-x,y}, {-x,-y}, {y,x}, {y,-x}, {-y,x}, {-y,-x}
        // 2. 每种变换一个编码：将island所有坐标点排序，然后坐标转换成 到第一点的偏移
        // 3. 取8个编码中排最前的一个作为island编码
        vector<vector<pair<int,int>>> trans(8);
        for (auto &pos : island) {
            int x = pos.first, y = pos.second;
            trans[0].push_back({x, y});
            trans[1].push_back({x, -y});
            trans[2].push_back({-x, y});
            trans[3].push_back({-x, -y});
            trans[4].push_back({y, x});
            trans[5].push_back({y, -x});
            trans[6].push_back({-y, x});            
            trans[7].push_back({-y, -x});
        }
        for (auto &tran : trans) {
            sort(tran.begin(), tran.end());
            for (int i = 1; i < tran.size(); i++) {
                tran[i].first -= tran[0].first;
                tran[i].second -= tran[0].second;
            }
            tran[0] = {0, 0};            
        }
        sort(trans.begin(), trans.end());
        island = trans[0];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
