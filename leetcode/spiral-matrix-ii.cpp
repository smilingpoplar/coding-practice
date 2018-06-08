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
        int r1 = 0, r2 = n - 1;
        int c1 = 0, c2 = n - 1;
        int count = 0;
        while (true) {
            // right
            if (r1 > r2 || c1 > c2) break;
            for (int c = c1; c <= c2; c++) {
                matrix[r1][c] = ++count;
            }
            r1++;
            // down
            if (r1 > r2 || c1 > c2) break;
            for (int r = r1; r <= r2; r++) {
                matrix[r][c2] = ++count;
            }
            c2--;
            // left
            if (r1 > r2 || c1 > c2) break;
            for (int c = c2; c >= c1; c--) {
                matrix[r2][c] = ++count;
            }
            r2--;
            // up
            if (r1 > r2 || c1 > c2) break;
            for (int r = r2; r >= r1; r--) {
                matrix[r][c1] = ++count;
            }
            c1++;
        }
        
        return matrix;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto matrix = solution.generateMatrix(3);
    for (const auto &row : matrix) {
        for (const auto num: row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
