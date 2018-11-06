//
//  combination-sum-iv
//  https://leetcode.com/problems/combination-sum-iv/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 和为i的子集排列数，递推式 dp[i]=sum(dp[i-num])
        // 子集排列数的写法刚好 将背包问题的外层物品循环改内层
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (int num : nums) {
                if (i - num >= 0) dp[i] += dp[i-num];
            }
        }
        return dp[target];        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
