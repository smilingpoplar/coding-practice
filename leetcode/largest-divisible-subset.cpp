//
//  largest-divisible-subset
//  https://leetcode.com/problems/largest-divisible-subset/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // 先排序数组。nums[i]能整除某子集的所有值 <=> nums[i]能整除该子集最大值
        // 设dp[i]表示以nums[i]结尾的nums[0..i]的最大可整除子集长，
        // 若 nums[i] % nums[j] == 0，j < i，则 dp[i] = max(dp[j]+1)
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        vector<int> dp(N, 1);
        vector<int> prev(N, -1);
        int maxlen = 0, maxidx = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) { // 能扩展
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
