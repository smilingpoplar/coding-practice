//
//  target-sum
//  https://leetcode.com/problems/target-sum/
//
//  Created by smilingpoplar on 17/10/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum < S || (sum - S) % 2 != 0) return 0;
        sum = (sum - S) / 2;

        // 01背包问题
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int j = sum; j >= num; --j) { // 逆序循环
                dp[j] += dp[j - num];
            }
        }
        return dp[sum];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
