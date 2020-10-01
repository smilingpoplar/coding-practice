//
//  stone-game-v
//  https://leetcode.com/problems/stone-game-v/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stones) {
        // 设dp[i][j]表示stones[i..j]的最大得分
        // dp[i][j] = max{ left+dp[i..k] 若left=sum[i..k]更小, 
        //                 right+dp[k+1..j] 若right=sum[k+1..j]更小) }
        // k在[i,j-1]。初始dp[i][i]=0
        const int N = stones.size();
        vector<int> presum(N + 1);
        for (int i = 0; i < N; i++) {
            presum[i+1] = presum[i] + stones[i];
        }
        vector<vector<int>> memo(N + 1, vector<int>(N + 1, -1));

        function<int(int, int)> dp = [&](int lo, int hi) {
            if (lo == hi) return 0;
            if (memo[lo][hi] != -1) return memo[lo][hi];

            int ans = 0;
            for (int k = lo; k < hi; k++) {
                int left = presum[k+1] - presum[lo];
                int right = presum[hi+1] - presum[k+1];
                if (left <= right) {
                    ans = max(ans, left + dp(lo, k));
                } 
                if (left >= right) {
                    ans = max(ans, right + dp(k+1, hi));
                } 
            }
            return memo[lo][hi] = ans;
        };
        return dp(0, N-1);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
