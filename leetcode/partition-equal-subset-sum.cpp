//
//  partition-equal-subset-sum
//  https://leetcode.com/problems/partition-equal-subset-sum/
//
//  Created by smilingpoplar on 17/10/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum % 2 == 1) return false;
        sum /= 2;

        // 找到一些数，使它们和等于sum，01背包问题
        // 设dp[i][j]表示前0..i个数的和等于j是否存在，dp[i][j] = dp[i-1][j] /*不取第i个数*/ || dp[i-1][j - nums[i]] /*取第i个数*/
        // 01背包问题的一维数组写法
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int j = sum; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[sum];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
