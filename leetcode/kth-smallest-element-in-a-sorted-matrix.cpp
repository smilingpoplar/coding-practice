//
//  kth-smallest-element-in-a-sorted-matrix
//  https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return INT_MIN;
        const int M = matrix.size();
        const int N = matrix[0].size();
        // 在值[matrix[0][0]..matrix[M-1][N-1]]中二分搜索找第k大的
        // 二分搜索要在[false,...,false,true,true...]中找第一个true
        // 函数kthOrLarger(value)判断value是否第k大或更大
        int l = matrix[0][0], u = matrix[M-1][N-1];
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (kthOrLarger(matrix, mid, k)) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    
    bool kthOrLarger(vector<vector<int>>& matrix, int value, int k) {
        int count = 0;
        for (auto &row : matrix) {
            // 看每行<=value的数有几个
            count += upper_bound(row.begin(), row.end(), value) - row.begin();
        }
        return count >= k;
    }
};
int main(int argc, const char * argv[]) {    
    return 0;
}
