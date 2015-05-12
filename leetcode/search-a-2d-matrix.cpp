//
//  search-a-2d-matrix
//  https://leetcode.com/problems/search-a-2d-matrix/
//
//  Created by smilingpoplar on 15/5/12.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 相当于在有序数组[0,M*N-1]中搜索，不变式：
        // | < t | == t | > t |   &&  l <= u
        // [l                u]
        if (matrix.empty()) return false;
        const int M = (int)matrix.size();
        const int N = (int)matrix[0].size();
        int l = 0;
        int u = M * N - 1;
        while (l <= u) {
            int mid = l + (u - l) / 2;
            int midValue = matrix[mid / N][mid % N];
            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                l = mid + 1;
            } else {
                u = mid - 1;
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
