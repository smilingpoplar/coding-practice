//
//  the-maze-ii
//  https://leetcode.com/problems/the-maze-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // dijkstra法，用优先队列，下一位置是向四个方向前进到碰墙处
        if (maze.empty()) return false;
        const int M = maze.size();
        const int N = maze[0].size();
        auto cmp = [](const vector<int> &a, const vector<int> &b) { // [row,col,dist]
            return a[2] > b[2]; // 最小堆
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({start[0], start[1], 0});
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int r = curr[0], c = curr[1];
            if (visited[r][c]) continue;
            visited[r][c] = true;
            if (r == destination[0] && c == destination[1]) return curr[2];
            
            for (auto &dir : dirs) {
                auto next = getNext(curr, dir, maze);
                pq.push(next); 
            }
        }
        return -1;
    }
    
    // 返回[row,col,dist]：下个点的坐标(row,col)，下个点距起点的距离dist
    vector<int> getNext(const vector<int> &pos, const vector<int> &dir, vector<vector<int>> &maze) {
        int r = pos[0], c = pos[1], dist = pos[2];
        int cost = 0;
        while (r >= 0 && r < maze.size() && c >= 0 && c < maze[0].size() && maze[r][c] == 0) {
            r += dir[0], c += dir[1], cost++;
        }
        r -= dir[0], c -= dir[1], cost--;
        return {r, c, dist + cost};
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
