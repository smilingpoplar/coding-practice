//
//  spiral-matrix
//  https://leetcode.com/problems/spiral-matrix/
//
//  Created by smilingpoplar on 15/5/12.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 从外层往内层、一层层打印
        vector<int> ans;
        if (matrix.empty()) return ans;
        const int M = matrix.size();
        const int N = matrix[0].size();
        // 各层左上角、右下角
        int r1 = 0, r2 = M - 1;
        int c1 = 0, c2 = N - 1;
        while (true) {
            // r1行
            for (int c = c1; c <= c2; c++) {
                ans.push_back(matrix[r1][c]);
            }
            ++r1;
            if (r1 > r2) break;
            // c2列
            for (int r = r1; r <= r2; r++) {
                ans.push_back(matrix[r][c2]);
            }
            --c2;
            if (c1 > c2) break;
            // r2行，从右往左
            for (int c = c2; c >= c1; c--) {
                ans.push_back(matrix[r2][c]);
            }
            --r2;
            if (r1 > r2) break;
            // c1列，从下往上
            for (int r = r2; r >= r1; r--) {
                ans.push_back(matrix[r][c1]);
            }
            ++c1;
            if (c1 > c2) break;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    Solution solution;
    auto result = solution.spiralOrder(matrix);
    for (auto num : result) {
        cout << num << " ";
    }
    
    return 0;
}
