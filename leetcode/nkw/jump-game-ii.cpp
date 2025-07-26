//
//  jump-game-ii
//  NC206 跳跃游戏(二)
//

#include <vector>
using namespace std;

class Solution {
public:
    int maxJumpGrade(vector<int>& nums) {
        // 若位置i和j（i<j）都能跳到终点，则i可以先跳到j再跳到终点，
        // 选j作为新终点（得分nums[i]+nums[j]）比选i作为新终点（得分nums[i]）更好
        // 贪婪法：选更靠后的可达位置作为新终点
        if (nums.empty()) return -1;
        const int N = nums.size();
        int ans = 0;
        int end = N - 1;
        for (int i = N - 1; i >= 0; i--) {
            if (i + nums[i] >= end) {
                end = i;
                ans += nums[i];
            }
        }
        return end == 0 ? ans : -1;
    }
};

/*
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
*/