//
//  minimum-falling-path-sum-ii
//  https://leetcode.com/problems/minimum-falling-path-sum-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        // 设dp[r][c]表示从第1行下降到arr[r][c]时的最小和
        // dp[r][c] = arr[r][c] + min(dp[r-1][notC])
        // 初始 dp[-1][c] = 0
        // 省掉第r维，r从左往右遍历，用临时变量ndp
        // ndp[c] = arr[r][c] + min(dp[notC])
        // min(dp[notC])只要记录最小值min1、最小值索引min1Idx，次小值min2
        const int R = arr.size(), C = arr[0].size();
        vector<int> dp(C); // r==-1
        int min1 = 0, min1Idx = -1, min2 = 0;
        for (int r = 0; r < R; r++) {
            vector<int> ndp(C);
            int tmp_min1 = INT_MAX, tmp_min1Idx = -1, tmp_min2 = INT_MAX;
            for (int c = 0; c < C; c++) {
                ndp[c] = arr[r][c] + ((c != min1Idx) ? min1 : min2);
                if (ndp[c] < tmp_min1) {
                    tmp_min2 = tmp_min1;
                    tmp_min1 = ndp[c];
                    tmp_min1Idx = c;
                } else if (ndp[c] < tmp_min2) {
                    tmp_min2 = ndp[c];
                }
            }
            swap(dp, ndp);
            min1 = tmp_min1, min1Idx = tmp_min1Idx, min2 = tmp_min2;
        }
        return *min_element(begin(dp), end(dp));
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
