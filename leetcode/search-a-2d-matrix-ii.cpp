//
//  search-a-2d-matrix-ii
//  https://leetcode.com/problems/search-a-2d-matrix-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // 从行列有序的”中间“位置（右上角或左下角）开始线性查找，O(m+n)
        if (matrix.empty()) return false;
        const int R = matrix.size(), C = matrix[0].size();
        int r = 0, c = C - 1;
        while (r < R && c >= 0) {
            if (target == matrix[r][c]) {
                return true;
            } else if (target > matrix[r][c]) {
                r++;
            } else {
                c--;
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
        const int R = matrix.size();
        const int C = matrix[0].size();
        return searchMatrix(matrix, target, 0, R - 1, 0, C - 1);
    }
private:
    // 在matrix[r1,r2][c1,c2]中搜索target
    // 四分后去一，复杂度递推式 T(n)=3T(n/2)+c，复杂度 O(n^log2{3})=O(n^1.58)
    // 可参考：http://articles.leetcode.com/2010/10/searching-2d-sorted-matrix-part-ii.html
    bool searchMatrix(vector<vector<int>> &matrix, int target, int r1, int r2, int c1, int c2) {
        if (r1 > r2 || c1 > c2) return false;
        int row = (r1 + r2) / 2;
        int col = (c1 + c2) / 2;
        if (target == matrix[row][col]) {
            return true;
        } else if (target < matrix[row][col]) { // 四分，包含matrix[row][col]的右下矩阵不用再找
            return searchMatrix(matrix, target, r1, row - 1, c1, c2)
            || searchMatrix(matrix, target, row, r2, c1, col - 1);
        } else { // 四分，包含matrix[row][col]的左上矩阵不用再找
            return searchMatrix(matrix, target, r1, row, col + 1, c2)
            || searchMatrix(matrix, target, row + 1, r2, c1, c2);
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
