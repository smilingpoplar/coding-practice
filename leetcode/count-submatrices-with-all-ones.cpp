//
//  count-submatrices-with-all-ones
//  https://leetcode.com/problems/count-submatrices-with-all-ones/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        // 把R行C列的矩阵看作R个以第r行为底的直方图
        if (mat.empty()) return 0;
        const int R = mat.size(), C = mat[0].size();
        int ans = 0;
        vector<int> h(C, 0);
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (mat[r][c] == 0) h[c] = 0;
                else h[c]++;
                // 统计以(r,c)为右下角的子矩阵数
                for (int lo = c, minH = INT_MAX; lo >= 0; lo--) {
                    minH = min(minH, h[lo]);
                    ans += minH;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
