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
        // 先排序数组。子集扩展到nums[i]的条件是 nums[i]能整除子集的所有值。
        // 因为子集末尾的最大值nums[j]能整除子集所有其他值，
        // 所以nums[i]只需整除nums[j]就能扩展该子集。
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        // 设dp[i]表示以nums[i]结尾的nums[0..i]的最大可整除子集长
        vector<int> dp(N, 1);
        vector<int> prev(N, -1); // 记录序列
        int maxlen = 0, maxidx = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) { // nums[i]能扩展以nums[j]结尾的子集
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
