//
//  n-queens
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
        vector<bool> cols(n, false);     // 某列是否被已放置的皇后占据
        vector<bool> diag(2 * n - 1, false);
        vector<bool> antiDiag(2 * n - 1, false);
        
        vector<vector<string>> ans;
        dfs(0, placement, cols, diag, antiDiag, ans);
        return ans;
    }
private:
    void dfs(int row, vector<int> &placement, vector<bool> &cols, vector<bool> &diag, vector<bool> &antiDiag, vector<vector<string>> &ans) {
        const int N = placement.size();
        if (row == N) { // 终止条件
            auto solution = genSolution(placement);
            ans.push_back(solution);
            return;
        }
        
        for (int col = 0; col < N; col++) {
            if (cols[col] || diag[row + col] || antiDiag[row - col + N - 1]) continue;
            // 执行动作
            placement[row] = col;
            cols[col] = diag[row + col] = antiDiag[row - col + N - 1] = true;
            // 递归
            dfs(row + 1, placement, cols, diag, antiDiag, ans);
            // 撤销动作
            placement[row] = -1;
            cols[col] = diag[row + col] = antiDiag[row - col + N - 1] = false;
        }
    }
    
    vector<string> genSolution(const vector<int> &placement) {
        const int N = placement.size();
        vector<string> solution;
        for (int i = 0; i < N; i++) {
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
        for (int i = 0; i < n; i++) {
            cout << solution[i] << endl;
        }
        cout << endl;
    }
    
    return 0;
}
