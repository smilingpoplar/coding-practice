//
//  longest-increasing-subsequence
//  https://leetcode.com/problems/longest-increasing-subsequence/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 设dp[i]表示以位置i结尾的nums[0..i]的最长递增子序列长，
        // dp[i] = max{1, dp[j]+1 | 0<=j<i且nums[j]<nums[i] }
        // 所求为 max{dp[i]}
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
        vector<int> tails;  // 保存各长度LIS的最小尾元素，是个递增数组
        for (int num : nums) {
            // 在tails[]中找第一个>=num的数
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it != tails.end())
                *it = num;  // 若找到，则用num替换该项（末尾变小、LIS长度不变）
            else
                tails.push_back(num);  // 若找不到，说明所有尾元素都<num，可扩展序列
        }
        return tails.size();
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
