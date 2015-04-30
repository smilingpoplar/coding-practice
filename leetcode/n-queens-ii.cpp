//
//  n-queens-ii.cpp
//  https://leetcode.com/problems/n-queens-ii/
//
//  Created by smilingpoplar on 15/4/30.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> placement(n, -1); // 按行放置，placement[i]=j 表示在i行的第j列放置皇后
        // 放置皇后的判断条件
        vector<bool> occupiedColumn(n, false);     // 某列是否被已放置的皇后占据
        vector<bool> occupiedMainDiagonal(2 * n - 1, false);
        vector<bool> occupiedAntiDiagonal(2 * n - 1, false);
        
        int total = 0;
        dfs(0, placement, occupiedColumn, occupiedMainDiagonal, occupiedAntiDiagonal, total);
        
        return total;
    }
private:
    void dfs(int row, vector<int> &placement, vector<bool> &occupiedColumn, vector<bool> &occupiedMainDiagonal, vector<bool> &occupiedAntiDiagonal, int &total) {
        const size_t N = placement.size();
        if (row == N) { // 终止条件
            ++total;
            return;
        }
        
        for (int column = 0; column < N; column++) {
            if (occupiedColumn[column] || occupiedMainDiagonal[row + column] || occupiedAntiDiagonal[row - column + N - 1]) continue;
            // 执行动作
            placement[row] = column;
            occupiedColumn[column] = occupiedMainDiagonal[row + column] = occupiedAntiDiagonal[row - column + N - 1] = true;
            // 递归
            dfs(row + 1, placement, occupiedColumn, occupiedMainDiagonal, occupiedAntiDiagonal, total);
            // 撤销动作
            placement[row] = -1;
            occupiedColumn[column] = occupiedMainDiagonal[row + column] = occupiedAntiDiagonal[row - column + N - 1] = false;
        }
    }
};

int main(int argc, const char * argv[]) {
    int n = 4;
    Solution solution;
    int total = solution.totalNQueens(n);
    cout << total;
    
    return 0;
}
