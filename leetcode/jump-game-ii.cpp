//
//  jump-game-ii
//  https://leetcode.com/problems/jump-game-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // 设dp[i]表示以nums[i]开头的nums[i..]的最小跳数
        // dp[i] = min{ 1 + dp[i + j]} , 0 < j <= nums[i] && i + j < N
        const int N = nums.size();
        const int INF = 1e5 + 7;
        vector<int> dp(N, INF);
        dp[N - 1] = 0;
        for (int i = N - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i] && i + j < N; j++) {
                dp[i] = min(dp[i], 1 + dp[i + j]);
            }
        }
        return dp[0];
    }
};

/*
class Solution {
public:
    int jump(vector<int>& nums) {
        // 点i覆盖[i,i+nums[i]]，需要到覆盖[0,N-1]
        const int N = nums.size();
        if (N <= 1) return 0;

        // 实际是bfs分层遍历
        int ans = 0;
        for (int i = 0, hi = 0; i <= hi;) {
            ans++; // 在nums[i]处跳
            int hi0 = hi;
            for (; i <= hi0; i++) {
                hi = max(hi, i + nums[i]);
                if (hi >= N - 1) return ans;
            }
        }
        return -1;
    }
};
*/

int main(int argc, const char* argv[]) {
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << solution.jump(nums);

    return 0;
}
