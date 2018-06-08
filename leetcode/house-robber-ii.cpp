//
//  house-robber-ii
//  https://leetcode.com/problems/house-robber-ii/
//
//  Created by smilingpoplar on 15/6/3.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        const int N = nums.size();
        if (N == 1) return nums[0];
        // 循环数组首尾不能同时选择，根据不能选尾元素还是不能选首元素，
        // 分成无循环的两个子问题rob(nums,0,n-2)和rob(nums,1,n-1)
        return max(subRob(nums, 0, N - 2), subRob(nums, 1, N - 1));
    }
    // rob nums[from,to]
    int subRob(const vector<int> &nums, int from, int to) {
        // 设dp[i]表示抢了nums[from..i]后的最大值，from<=i<=to
        // dp[i] = max( nums[i]+dp[i-2], dp[i-1] )，初始dp[from-2]=dp[from-1]=0
        // 看递推式当前项只依赖于前两项，前两项分别用prev2和prev1表示
        int prev2 = 0, prev1 = 0;
        for (int i = from; i <= to; i++) {
            int curr = max(nums[i] + prev2, prev1);
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