//
//  target-sum
//  https://leetcode.com/problems/target-sum/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // 设加正号的子集和为A，加负号的子集和为B，则A-B=S；又A+B=sum，所以
        // A = (S+sum)/2，B = (sum-S)/2，要满足sum>=S且sum-S为偶数
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum < S || (sum - S) % 2 != 0) return 0;
        int target = (sum - S) / 2;

        // 01背包问题
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int i = target; i >= num; i--) {  // 逆序循环
                dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
