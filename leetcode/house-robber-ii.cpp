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
        // 若不抢房子i，就能从i处将循环数组切断，变成无循环数组的子问题。
        // 相邻两个房子不能同时抢，从相邻两个房子分别切开，就能得到两个无循环子问题。
        // 不妨不能同时抢首尾两个房子，得到无循环的子问题 rob(nums,1,n-1)和rob(nums,0,n-2)
        return max(robSub(nums, 1, N - 1), robSub(nums, 0, N - 2));
    }
    // rob nums[from,to]
    int robSub(const vector<int> &nums, int from, int to) {
        // 设dp[i]表示抢了nums[0..i]后的最大值，0<=i<N
        // dp[i] = max( dp[i-1], nums[i]+dp[i-2] )，初始dp[-2]=dp[-1]=0
        // 看递推式只依赖于前两项，前两项分别用prev2和prev1表示
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