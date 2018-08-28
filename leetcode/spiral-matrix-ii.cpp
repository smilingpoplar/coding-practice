//
//  spiral-matrix-ii
//  https://leetcode.com/problems/spiral-matrix-ii/
//
//  Created by smilingpoplar on 15/5/12.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int r1 = 0, r2 = n - 1, c1 = 0, c2 = n - 1;
        int cnt = 0;
        while (true) {
            // right
            if (c1 > c2) break;
            for (int c = c1; c <= c2; c++) {
                matrix[r1][c] = ++cnt;
            }
            r1++;
            // down
            if (r1 > r2) break;
            for (int r = r1; r <= r2; r++) {
                matrix[r][c2] = ++cnt;
            }
            c2--;
            // left
            if (c1 > c2) break;
            for (int c = c2; c >= c1; c--) {
                matrix[r2][c] = ++cnt;
            }
            r2--;
            // up
            if (r1 > r2) break;
            for (int r = r2; r >= r1; r--) {
                matrix[r][c1] = ++cnt;
            }
            c1++;
        }
        return matrix;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto matrix = solution.generateMatrix(3);
    for (auto &row : matrix) {
        for (auto val: row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
