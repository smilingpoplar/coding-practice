//
//  minimum-difficulty-of-a-job-schedule
//  https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& A, int d) {
        // 题目: 分段最大值的最小和
        // 设dp[i][d]表示子问题A[i..]还剩d天的最优解
        // dp[i][d] = max(A[i..k]) + dp[k+1][d-1], i<=k<=N-1
        // 初始 dp[N][0]=0，dp[N][>d]=INF，dp[<N][0]=INF
        const int INF = 1e9;
        const int N = A.size();
        vector<vector<int>> memo(N + 1, vector<int>(d + 1, -1));
        function<int(int,int)> dp = [&](int idx, int d) {
            if (idx == N && d == 0) return 0;
            if (idx == N || d == 0) return INF;
            if (memo[idx][d] != -1) return memo[idx][d];

            int maxL = 0, ans = INF;
            for (int k = idx; k <= N - 1; k++) {
                maxL = max(maxL, A[k]);
                ans = min(ans, dp(k + 1, d - 1) + maxL);
            }
            return memo[idx][d] = ans;
        };

        int ans = dp(0, d);
        return ans == INF ? -1 : ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
