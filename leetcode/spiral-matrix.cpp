//
//  spiral-matrix
//  https://leetcode.com/problems/spiral-matrix/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        const int R = matrix.size(), C = matrix[0].size();
        const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 右下左上
        vector<int> numSteps = {C, R - 1};
        int r = 0, c = -1;
        int cur = 0;  // 方向，4种
        vector<int> ans;
        while (numSteps[cur % 2]) {
            for (int i = 0; i < numSteps[cur % 2]; i++) {
                r += dirs[cur][0], c += dirs[cur][1];
                ans.push_back(matrix[r][c]);
            }
            numSteps[cur % 2]--;
            cur = (cur + 1) % 4;
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 从外层往内层、一层层打印
        vector<int> ans;
        if (matrix.empty()) return ans;
        const int R = matrix.size(), C = matrix[0].size();
        // 各层左上角、右下角
        int r1 = 0, r2 = R - 1, c1 = 0, c2 = C - 1;
        while (true) {
            // r1行
            if (c1 > c2) break;
            for (int c = c1; c <= c2; c++) {
                ans.push_back(matrix[r1][c]);
            }
            r1++;
            // c2列
            if (r1 > r2) break;
            for (int r = r1; r <= r2; r++) {
                ans.push_back(matrix[r][c2]);
            }
            c2--;
            // r2行，从右往左
            if (c1 > c2) break;
            for (int c = c2; c >= c1; c--) {
                ans.push_back(matrix[r2][c]);
            }
            r2--;
            // c1列，从下往上
            if (r1 > r2) break;
            for (int r = r2; r >= r1; r--) {
                ans.push_back(matrix[r][c1]);
            }
            c1++;
        }
        return ans;
    }
};
*/

int main(int argc, const char* argv[]) {
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
