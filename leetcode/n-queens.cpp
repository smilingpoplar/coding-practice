//
//  n-queens.cpp
//  https://leetcode.com/problems/n-queens/
//
//  Created by smilingpoplar on 15/4/30.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> placement(n, -1); // 按行放置，placement[i]=j 表示在i行的第j列放置皇后
        // 放置皇后的判断条件
        vector<bool> occupiedColumn(n, false);     // 某列是否被已放置的皇后占据
        vector<bool> occupiedMainDiagonal(2 * n - 1, false);
        vector<bool> occupiedAntiDiagonal(2 * n - 1, false);
        
        vector<vector<string>> allSolutions;
        dfs(0, placement, occupiedColumn, occupiedMainDiagonal, occupiedAntiDiagonal, allSolutions);
        
        return allSolutions;
    }
private:
    void dfs(int row, vector<int> &placement, vector<bool> &occupiedColumn, vector<bool> &occupiedMainDiagonal, vector<bool> &occupiedAntiDiagonal, vector<vector<string>> &allSolutions) {
        const size_t N = placement.size();
        if (row == N) { // 终止条件
            auto solution = generateSolution(placement);
            allSolutions.push_back(solution);
            return;
        }
        
        for (int column = 0; column < N; column++) {
            if (occupiedColumn[column] || occupiedMainDiagonal[row + column] || occupiedAntiDiagonal[row - column + N - 1]) continue;
            // 执行动作
            placement[row] = column;
            occupiedColumn[column] = occupiedMainDiagonal[row + column] = occupiedAntiDiagonal[row - column + N - 1] = true;
            // 递归
            dfs(row + 1, placement, occupiedColumn, occupiedMainDiagonal, occupiedAntiDiagonal, allSolutions);
            // 撤销动作
            placement[row] = -1;
            occupiedColumn[column] = occupiedMainDiagonal[row + column] = occupiedAntiDiagonal[row - column + N - 1] = false;
        }
    }
    
    vector<string> generateSolution(const vector<int> &placement) {
        const size_t N = placement.size();
        vector<string> solution;
        for (size_t i = 0; i < N; i++) {
            string s(N, '.');
            s[placement[i]] = 'Q';
            solution.push_back(s);
        }
        return solution;
    }
};

int main(int argc, const char * argv[]) {
    int n = 4;
    Solution solution;
    auto solutions = solution.solveNQueens(n);
    for (const auto &solution : solutions) {
        for (size_t i = 0; i < n; i++) {
            cout << solution[i] << endl;
        }
        cout << endl;
    }
    
    return 0;
}
