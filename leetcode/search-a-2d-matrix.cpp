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
        // 相当于在有序数组A[0,M*N)中搜索
        // 不变式：A[l]<=target<A[u]（l<u）（即A[l,u)是数组中可能包含target的部分）
        if (matrix.empty()) return false;
        const int M = (int)matrix.size();
        const int N = (int)matrix[0].size();
        int l = 0;
        int u = M * N;
        while (l < u) {
            int mid = l + (u - l) / 2;
            int midValue = matrix[mid / N][mid % N];
            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                l = mid + 1;
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
