//
//  longest-increasing-subsequence
//  https://leetcode.com/problems/longest-increasing-subsequence/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 设dp[i]表示nums[0..i]的最长递增子序列
        const int N = nums.size();
        vector<int> dp(N, 1);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails; // 各长度LIS的最小尾元素
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it != tails.end()) *it = num;
            else tails.push_back(num);
        }
        return tails.size();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
