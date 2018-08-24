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
        // 按行放置，place[i]=j 表示在第i行的第j列放置皇后
        vector<int> place(n, -1);
        // 放置皇后时的判断条件
        vector<bool> cols(n, false), diag(2 * n - 1, false), antidiag(2 * n - 1, false);

        vector<vector<string>> ans;
        search(0, place, cols, diag, antidiag, ans);
        return ans;
    }

    void search(int r, vector<int> &place, vector<bool> &cols,
                vector<bool> &diag, vector<bool> &antidiag, vector<vector<string>> &ans) {
        const int N = place.size();
        if (r == N) {
            auto solution = getSolution(place);
            ans.push_back(solution);
            return;
        }
        
        for (int c = 0; c < N; c++) {
            if (cols[c] || diag[r + c] || antidiag[r - c + N - 1]) continue;
            place[r] = c;
            cols[c] = diag[r + c] = antidiag[r - c + N - 1] = true;
            search(r + 1, place, cols, diag, antidiag, ans);
            place[r] = -1;
            cols[c] = diag[r + c] = antidiag[r - c + N - 1] = false;
        }
    }
    
    vector<string> getSolution(const vector<int> &place) {
        const int N = place.size();
        vector<string> solution;
        for (int i = 0; i < N; i++) {
            string s(N, '.');
            s[place[i]] = 'Q';
            solution.push_back(s);
        }
        return solution;
    }
};

int main(int argc, const char * argv[]) {
    int n = 4;
    Solution solution;
    auto solutions = solution.solveNQueens(n);
    for (auto &solution : solutions) {
        for (int i = 0; i < n; i++) {
            cout << solution[i] << endl;
        }
        cout << endl;
    }
    
    return 0;
}
