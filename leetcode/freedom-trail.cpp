//
//  freedom-trail
//  https://leetcode.com/problems/freedom-trail/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        // 设dp[r][k]表示从ring[r]对齐12点开始，输入所有key[k..]的字符，最少需要旋转多少次。
        // 考虑输入key[k]最少需要旋转多少次。遍历ring中字符，当ring[i]==key[k]时，把ring[i]转到对齐12点，
        // 需要旋转 diff = abs(i-r), step = min(diff, R-diff) 次
        // dp[r][k] = min{ step + dp[i][k+1] | for all ring[i]==key[k] }
        // 初始dp[][K]=0，表示key输入完成的情况
        const int R = ring.size(), K = key.size();
        vector<vector<int>> dp(R, vector<int>(K + 1, INT_MAX));
        for (int r = 0; r < R; r++) dp[r][K] = 0;
        
        // 递推式在k这维只依赖于k+1项，要从右往左遍历k
        // 由已知dp[][K]递推，要先算k这维
        for (int k = K - 1; k >= 0; k--) {
            for (int r = 0; r < R; r++) {
                for (int i = 0; i < R; i++) {
                    if (ring[i] == key[k]) {
                        int diff = abs(i - r);
                        int step = min(diff, R - diff);
                        dp[r][k] = min(dp[r][k], step + dp[i][k+1]);
                    }
                }
            }
        }
        return dp[0][0] + K;
    }
};

/*
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> memo(ring.size(), vector<int>(key.size(), -1));
        return search(ring, 0, key, 0, memo);
    }
    
    // 从ring[r]对齐12点开始，旋转成ring中的key[k]字符对齐12点
    int search(const string &ring, int r, const string &key, int k, vector<vector<int>> &memo) {
        if (k == key.size()) return 0;
        if (memo[r][k] != -1) return memo[r][k];
        
        int ans = INT_MAX;
        const int R = ring.size();
        for (int i = 0; i < R; i++) {
            if (ring[i] == key[k]) {
                int steps = abs(i - r);
                steps = min(steps, R - steps);
                steps++; // press button;
                steps += search(ring, i, key, k + 1, memo);
                ans = min(ans, steps);
            }
        }
        memo[r][k] = ans;
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
