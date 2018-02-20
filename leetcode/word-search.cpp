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
        const size_t M = board.size();
        const size_t N = board[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        w
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (exist(board, i, j, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool exist(const vector<vector<char>>& board, int row, int column, const string &word, int index, vector<vector<bool>> &visited) {
        if (board.empty()) return false;
        const size_t M = board.size();
        const size_t N = board[0].size();
        if (index >= word.size()) return true;

        if (row < 0 || row >= M) return false;
        if (column < 0 || column >= N) return false;
        if (visited[row][column]) return false;
        if (board[row][column] != word[index]) return false;

        visited[row][column] = true;
        bool result = exist(board, row - 1, column, word, index + 1, visited)
        || exist(board, row + 1, column, word, index + 1, visited)
        || exist(board, row, column - 1, word, index + 1, visited)
        || exist(board, row, column + 1, word, index + 1, visited);
        visited[row][column] = false;
        
        return result;
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
