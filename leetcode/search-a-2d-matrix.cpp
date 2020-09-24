//
//  search-a-2d-matrix
//  https://leetcode.com/problems/search-a-2d-matrix/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 相当于在有序数组A[0,M*N)中搜索
        // 不变式：A[l,u)是数组中可能包含target的部分
        if (matrix.empty()) return false;
        const int M = matrix.size(), N = matrix[0].size();
        int l = -1, u = M * N;
        while (l + 1 < u) {
            int mid = l + (u - l) / 2;
            int midValue = matrix[mid / N][mid % N];
            if (target == midValue) {
                return true;
            } else if (target > midValue) {
                l = mid;
            } else {
                u = mid;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix {
        {1, 1}
    };
    int target = 2;
    Solution solution;
    cout << solution.searchMatrix(matrix, target);
    
    return 0;
}
