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
        int rowBegin = 0;
        int rowEnd = n - 1;
        int colBegin = 0;
        int colEnd = n - 1;
        int count = 0;
        while (true) {
            // right
            if (rowBegin > rowEnd || colBegin > colEnd) break;
            for (int i = colBegin; i <= colEnd; ++i) {
                matrix[rowBegin][i] = ++count;
            }
            ++rowBegin;
            // down
            if (rowBegin > rowEnd || colBegin > colEnd) break;
            for (int i = rowBegin; i <= rowEnd; ++i) {
                matrix[i][colEnd] = ++count;
            }
            --colEnd;
            // left
            if (rowBegin > rowEnd || colBegin > colEnd) break;
            for (int i = colEnd; i >= colBegin; --i) {
                matrix[rowEnd][i] = ++count;
            }
            --rowEnd;
            // up
            if (rowBegin > rowEnd || colBegin > colEnd) break;
            for (int i = rowEnd; i >= rowBegin; --i) {
                matrix[i][colBegin] = ++count;
            }
            ++colBegin;
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
