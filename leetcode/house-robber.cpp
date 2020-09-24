//
//  house-robber
//  https://leetcode.com/problems/house-robber/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // 设dp[i]表示抢了nums[0..i]后的最大值，0<=i<N
        // dp[i] = max( dp[i-1], nums[i]+dp[i-2] )，初始dp[-2]=dp[-1]=0
        // 递推式只依赖于前两项，记前两项为prev2和prev1
        int prev2 = 0, prev1 = 0;
        for (int num : nums) {
            int curr = max(prev1, num + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,20,100,2};
    Solution solution;
    cout << solution.rob(nums);
    
    return 0;
}
