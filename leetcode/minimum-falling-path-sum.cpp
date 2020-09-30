//
//  minimum-falling-path-sum
//  https://leetcode.com/problems/minimum-falling-path-sum/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        // 设dp[r][c]表示从第1行下降到A[r][c]时的最小和
        // dp[r][c] = A[r][c] + min(dp[r-1][c-1], dp[r-1][c], dp[r-1][c+1])
        // 初始 dp[-1][c] = 0
        // 省掉第r维，r从左往右遍历，用临时变量ndp
        // ndp[c] = A[r][c] + min(dp[c-1], dp[c], dp[c+1])
        const int R = A.size(), C = A[0].size();
        vector<int> dp(C); // r==-1
        for (int r = 0; r < R; r++) {
            vector<int> ndp(C);
            for (int c = 0; c < C; c++) {
                ndp[c] = A[r][c] + min({c-1 >= 0 ? dp[c-1] : INT_MAX, 
                                        dp[c], 
                                        c+1 < C ? dp[c+1] : INT_MAX});
            }
            swap(dp, ndp);
        }
        return *min_element(begin(dp), end(dp));
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
