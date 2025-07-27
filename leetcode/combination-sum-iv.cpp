//
//  combination-sum-iv
//  https://leetcode.com/problems/combination-sum-iv/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 和为i的子集排列数 dp[i]=sum(dp[i-num])
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i - num >= 0) dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
