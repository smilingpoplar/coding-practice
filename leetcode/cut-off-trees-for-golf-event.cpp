//
//  cut-off-trees-for-golf-event
//  https://leetcode.com/problems/cut-off-trees-for-golf-event/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty()) return 0;
        const int M = forest.size();
        const int N = forest[0].size();
        vector<vector<int>> idices;
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (forest[r][c] > 0) 
                    idices.push_back({r, c});
            }
        }
        sort(idices.begin(), idices.end(), [&forest](const vector<int> &a, const vector<int> &b) {
            return forest[a[0]][a[1]] < forest[b[0]][b[1]];
        });
        
        int ans = 0;
        int r = 0, c = 0;
        for (auto &idx : idices) {
            int d = dist(r, c, idx[0], idx[1], forest);
            if (d == -1) return -1;
            ans += d;
            r = idx[0], c = idx[1];
        }
        return ans;
    }
    
    int dist(int sr, int sc, int tr, int tc, vector<vector<int>>& forest) {
        // bst求最短距离
        const int M = forest.size();
        const int N = forest[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});

        int ans = 0;
        while (!q.empty()) {
            for (int n = q.size(); n > 0; n--) {
                auto node = q.front(); q.pop();
                int r = node.first, c = node.second;
                if (r < 0 || r >= M || c < 0 || c >= N || visited[r][c] || forest[r][c] == 0) continue;
                visited[r][c] = true;
                if (r == tr && c == tc) return ans;
                
                for (auto &dir : dirs) {
                    int nr = r + dir[0], nc = c + dir[1];
                    q.push({nr, nc});
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
