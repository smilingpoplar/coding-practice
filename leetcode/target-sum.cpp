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
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum < S || (sum - S) % 2 != 0) return 0;
        sum = (sum - S) / 2;

        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
