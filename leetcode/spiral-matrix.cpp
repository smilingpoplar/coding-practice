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
        vector<int> result;
        if (matrix.empty()) return result;
        const int M = (int)matrix.size();
        const int N = (int)matrix[0].size();
        int rowBegin = 0;
        int rowEnd = M - 1;
        int colBegin = 0;
        int colEnd = N - 1;
        while (true) {
            // right
            if (rowBegin > rowEnd || colBegin > colEnd) break;
            for (int i = colBegin; i <= colEnd; i++) {
                result.push_back(matrix[rowBegin][i]);
            }
            ++rowBegin;
            // down
            if (rowBegin > rowEnd || colBegin > colEnd) break;
            for (int i = rowBegin; i <= rowEnd; i++) {
                result.push_back(matrix[i][colEnd]);
            }
            --colEnd;
            // left
            if (rowBegin > rowEnd || colBegin > colEnd) break;
            for (int i = colEnd; i >= colBegin; i--) {
                result.push_back(matrix[rowEnd][i]);
            }
            --rowEnd;
            // up
            if (rowBegin > rowEnd || colBegin > colEnd) break;
            for (int i = rowEnd; i >= rowBegin; i--) {
                result.push_back(matrix[i][colBegin]);
            }
            ++colBegin;
        }
        
        return result;
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
