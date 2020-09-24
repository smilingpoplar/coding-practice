//
//  count-negative-numbers-in-a-sorted-matrix
//  https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // 从行列有序的"中间"位置（右上角或左下角）开始线性查找，O(m+n)
        if (grid.empty()) return false;
        const int R = grid.size(), C = grid[0].size();
        int r = 0, c = C - 1;
        int ans = 0;
        while (r < R && c >= 0) {
            if (grid[r][c] < 0) { // 类似找0的位置
                c--;
                ans += R - r;
            } else {
                r++;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
