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
        for (int num : nums)
            sum += num;
        if (sum % 2 == 1) return false;
        sum /= 2;

        // 找到一些数，使它们和等于sum，01背包问题
        // 设dp[i][j]表示[0..i)的和等于j，
        // dp[i][j] = dp[i-1][j] /*不取第i个数*/ || dp[i-1][j-nums[i]] /*取第i个数*/
        // 初始dp[0][0]=true
        // 省掉i维，i仍从左往右遍历，为让dp[j-nums[i]]表示旧状态，j从右往左遍历，
        // dp[j] = dp[j] || dp[j-nums[i]]
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int j = sum; j >= num; j--) {
                dp[j] = dp[j] || dp[j-num];
            }
        }
        return dp[sum];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
