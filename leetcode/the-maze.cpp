//
//  the-maze
//  https://leetcode.com/problems/the-maze/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // bfs，下一位置是向四个方向前进到碰墙处
        if (maze.empty()) return false;
        const int M = maze.size();
        const int N = maze[0].size();
        queue<vector<int>> q;
        q.push(start);
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        visited[start[0]][start[1]] = true;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            auto top = q.front(); q.pop();
            if (top[0] == destination[0] && top[1] == destination[1]) return true;
            for (auto &dir : dirs) {
                auto next = getNext(top, dir, maze);
                int nr = next[0], nc = next[1];
                if (visited[nr][nc]) continue;
                visited[nr][nc] = true;
                q.push(next);
            }
        }
        return false;
    }
 
    vector<int> getNext(vector<int> &pos, vector<int> &dir, vector<vector<int>> &maze) {
        int r = pos[0], c = pos[1];
        while (r >= 0 && r < maze.size() && c >= 0 && c < maze[0].size() && maze[r][c] == 0) {
            r += dir[0], c += dir[1];
        }
        r -= dir[0], c -= dir[1];
        return {r, c};
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
