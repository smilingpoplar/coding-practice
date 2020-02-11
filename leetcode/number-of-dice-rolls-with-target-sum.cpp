//
//  number-of-dice-rolls-with-target-sum
//  https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        // 取d次数，每次在[1..f]，总和为target
        // 设dp[i][j]表示取i次数、总和为j的子问题解
        // dp[i][j] += dp[i-1][j-k], k为[1..f]。
        // 初始dp[0][0]=1
        // 第i项只依赖i-1项，省掉第i项，i仍从左往右遍历；
        // 初始值dp[0][0]=1与后续迭代dp[>0][0]=0冲突，要使用临时变量ndp
        // ndp[j] += ndp[j-k]，k为[1..f]，j遍历顺序任意
        // 01背包，分组
        const int MOD = 1e9 + 7;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < d; i++) {
            vector<int> ndp(target + 1, 0);
            for (int k = 1; k <= f; k++) {
                for (int j = k; j <= target; j++) {
                    ndp[j] = (ndp[j] + dp[j-k]) % MOD;
                }
            }
            swap(dp, ndp);
        }
        return dp[target];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
