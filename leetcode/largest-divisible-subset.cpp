//
//  largest-divisible-subset
//  https://leetcode.com/problems/largest-divisible-subset/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        // 类似最长递增子序列的动态规划解法
        // 设dp[i]表示以nums[i]结尾的nums[0..i]的最大可整除子序列长
        vector<int> dp(N, 1);
        vector<int> prev(N, -1); // 重建序列用
        int maxlen = 0, maxidx = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) { // nums[i]可扩展以nums[j]结尾的子序列
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > maxlen) {
                maxlen = dp[i];
                maxidx = i;
            }
        }
        
        vector<int> ans;
        for (int i = maxidx; i != -1; i = prev[i]) {
            ans.push_back(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
