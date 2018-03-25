//
  //  the-maze-iii
  //  https://leetcode.com/problems/the-maze-iii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    struct Info {
        int row;
        int col;
        int dist;
        string moves;
        
        // priority_queue的比较函数，符合条件的留在队中
        bool operator<(const Info &rhs) const {
            if (dist == rhs.dist) return moves > rhs.moves;
            return dist > rhs.dist;
        }
    };
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        // dijkstra算法，用优先队列，下一位置是向四个方向前进到碰墙处
        if (maze.empty()) return "";
        const int M = maze.size();
        const int N = maze[0].size();
        priority_queue<Info> pq;
        pq.push({ball[0], ball[1], 0, ""});
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        const string dirsStr = "dlru";
        const vector<vector<int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
            
        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            if (visited[curr.row][curr.col]) continue;
            visited[curr.row][curr.col] = true;
            if (curr.row == hole[0] && curr.col == hole[1]) return curr.moves;

            for (int i = 0; i < dirs.size(); i++) {
                auto next = getNext(curr, dirs[i], dirsStr[i], maze, hole);
                pq.push(next); 
            }
        }
        return "impossible";
    }
    
    // 碰墙或掉洞
    Info getNext(const Info &info, const vector<int> &dir, char dirChar,
                 vector<vector<int>> &maze, vector<int> &hole) {
        int r = info.row, c = info.col;
        int cost = 0;
        while (r >= 0 && r < maze.size() && c >= 0 && c < maze[0].size()
               && maze[r][c] == 0 && !(r == hole[0] && c == hole[1])) { // 不是墙也不是洞
            r += dir[0], c += dir[1], cost++;
        }
        if (!(r == hole[0] && c == hole[1])) { // 不是洞，回退一步
            r -= dir[0], c -= dir[1], cost--;
        }
        return {r, c, info.dist + cost, info.moves + dirChar};
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
