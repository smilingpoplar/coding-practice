//
//  sliding-puzzle
//  https://leetcode.com/problems/sliding-puzzle/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // 棋盘状态间的转化，用str表示棋盘状态，用bfs搜索
        string src;
        for (auto &row : board) {
            for (int num : row) {
                src.push_back(num + '0');
            }
        }
        string target = "123450";

        queue<string> q;
        q.push(src);
        set<string> visited;
        visited.insert(src);
        
        int move = 0;
        while (!q.empty()) {
            for (int sz = q.size(); sz > 0; sz--) {
                auto state = q.front(); q.pop();
                if (state == target) return move;
                
                int pos = state.find('0');
                auto swapable = swapableIndice(pos);
                for (int idx : swapable) {
                    swap(state[pos], state[idx]);
                    if (!visited.count(state)) {
                        q.push(state);
                        visited.insert(state);
                    }
                    swap(state[pos], state[idx]);
                }                
            }
            move++;
        }
        return -1;
    }
    
    vector<int> swapableIndice(int pos) {
        // 找到'0'的位置，它可以跟上下左右交换
        const int M = 2;
        const int N = 3;
        int r = pos / N, c = pos % N;

        vector<int> ans;
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (auto &dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];
            if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
            ans.push_back(nr * N + nc);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
