//
//  jump-game-ii
//  NC206 跳跃游戏(二)
//

#include <climits>
class Solution {
public:
    int maxJumpGrade(vector<int>& nums) {
        // 设dp[i]表示以nums[i]开头的nums[i..]的最大积分
        // dp[i] = max{ nums[i] + dp[i + j]} , 0 < j <= nums[i] && i + j < N
        if (nums.empty()) return -1;
        const int N = nums.size();
        vector<int> dp(N, INT_MIN);
        dp[N - 1] = nums[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i] && i + j < N; j++) {
                dp[i] = max(dp[i], nums[i] + dp[i + j]);
            }
        }
        return dp[0] < 0 ? -1 : dp[0];
    }
};