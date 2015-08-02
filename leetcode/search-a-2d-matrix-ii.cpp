//
//  search-a-2d-matrix-ii
//  https://leetcode.com/problems/search-a-2d-matrix-ii/
//
//  Created by smilingpoplar on 15/8/2.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // 线性搜索，O(m+n)，从右上角开始找（或从左下角开始找）
        if (matrix.empty()) return false;
        const int M = (int)matrix.size();
        const int N = (int)matrix[0].size();
        int row = 0;
        int col = N - 1;
        while (row < M && col >= 0) {
            if (target == matrix[row][col]) {
                return true;
            } else if (target > matrix[row][col]) {
                ++row;
            } else {
                --col;
            }
        }
        return false;
    }
};

/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) return false;
        const int M = (int)matrix.size();
        const int N = (int)matrix[0].size();
        return searchMatrix(matrix, target, 0, M - 1, 0, N - 1);
    }
private:
    // 在matrix[rowStart,rowEnd][colStart,colEnd]中搜索target
    // 四分后去一，复杂度递推式 T(n)=3T(n/2)+c，复杂度 O(n^log2{3})=O(n^1.58)
    // 可参考：http://articles.leetcode.com/2010/10/searching-2d-sorted-matrix-part-ii.html
    bool searchMatrix(vector<vector<int>> &matrix, int target, int rowStart, int rowEnd, int colStart, int colEnd) {
        if (rowStart > rowEnd || colStart > colEnd) return false;
        int row = (rowStart + rowEnd) / 2;
        int col = (colStart + colEnd) / 2;
        if (target == matrix[row][col]) {
            return true;
        } else if (target < matrix[row][col]) { // 四分，包含matrix[row][col]的右下矩阵不用再找
            return searchMatrix(matrix, target, rowStart, row - 1, colStart, colEnd)
            || searchMatrix(matrix, target, row, rowEnd, colStart, col - 1);
        } else { // 四分，包含matrix[row][col]的左上矩阵不用再找
            return searchMatrix(matrix, target, rowStart, row, col + 1, colEnd)
            || searchMatrix(matrix, target, row + 1, rowEnd, colStart, colEnd);
        }
    }
};
*/

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix {
        {1, 4},
        {2, 5},
    };
    int target = 2;
    Solution solution;
    cout << solution.searchMatrix(matrix, target);
    
    return 0;
}
