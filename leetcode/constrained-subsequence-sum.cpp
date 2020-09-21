//
//  maximal-square
//  https://leetcode.com/problems/maximal-square/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // 设dp[i]表示以nums[i]结尾的nums[0..i]的最大子序列和，
        // dp[i] = nums[i] + max{ dp[i-k], ..., dp[i-2], dp[i-1], 0 }
        // 用可取最大值的单调递减队列q，保存dp前k项[i-k..i-1]
        // 初始dp[0]=nums[0]
        const int N = nums.size();
        vector<int> dp(N);
        dp[0] = nums[0];
        deque<int> q = {{dp[0]}};
        int ans = dp[0];
        
        for (int i = 1; i < N; i++) {
            if (i-k-1 >= 0 && q[0] == dp[i-k-1]) q.pop_front();
            dp[i] = nums[i] + max(q[0], 0);
            while (!q.empty() && dp[i] > q.back()) { // 递减队列
                q.pop_back();
            }
            q.push_back(dp[i]);

            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
