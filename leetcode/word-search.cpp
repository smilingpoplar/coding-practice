//
//  word-search
//  https://leetcode.com/problems/word-search/
//
//  Created by smilingpoplar on 15/5/2.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int R = board.size(), C = board[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (dfs(board, r, c, word, 0, visited)) return true;
            }
        }
        return false;
    }

    bool dfs(const vector<vector<char>>& board, int r, int c, 
            const string &word, int idx, vector<vector<bool>> &visited) {
        if (board.empty()) return false;
        const int R = board.size(), C = board[0].size();
        if (idx >= word.size()) return true;

        if (r < 0 || r >= R || c < 0 || c >= C
            || visited[r][c] || board[r][c] != word[idx]) return false;

        visited[r][c] = true;
        bool ans = dfs(board, r - 1, c, word, idx + 1, visited)
                || dfs(board, r + 1, c, word, idx + 1, visited)
                || dfs(board, r, c - 1, word, idx + 1, visited)
                || dfs(board, r, c + 1, word, idx + 1, visited);
        visited[r][c] = false;
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    Solution solution;
    cout << solution.exist(board, "SEE");
    
    return 0;
}
