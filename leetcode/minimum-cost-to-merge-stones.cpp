//
//  minimum-cost-to-merge-stones
//  https://leetcode.com/problems/minimum-cost-to-merge-stones/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        const int INF = 1e9;
        const int N = stones.size();
        // 就像汽水瓶换汽水的问题
        if ((N - 1) % (K - 1) != 0) return -1;
        // 设dp[i][j][m]表示把stones[i..j]合成m堆
        // dp[i][j][m] = min{ dp[i][mid][1] + dp[mid+1][j][m-1] }, mid在[i..j-m+1]
        // 初始dp[i][i][1]=0，dp[i][i][>1]=INF
        // 已知可合并，dp[i][j][1]=dp[i][j][K]+sum[i..j]

        vector<int> presum(N + 1);
        for (int i = 0; i < N; i++) {
            presum[i+1] = presum[i] + stones[i];
        } // sum[i..j]=presum[j+1]-presum[i]
        vector<vector<vector<int>>> memo(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, -1)));
        function<int(int, int, int)> dp = [&](int lo, int hi, int m) {
            if (lo == hi) return m == 1 ? 0 : INF;
            if (m == 1) return dp(lo, hi, K) + presum[hi+1] - presum[lo];
            if (memo[lo][hi][m] != -1) return memo[lo][hi][m];
            
            int ans = INF;
            for (int mid = lo; mid <= hi - m + 1; mid++) {
                ans = min(ans, dp(lo, mid, 1) + dp(mid + 1, hi, m - 1));
            }
            return memo[lo][hi][m] = ans;
        };
        return dp(0, N - 1, 1);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
