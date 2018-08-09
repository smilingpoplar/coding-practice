//
//  k-inverse-pairs-array
//  https://leetcode.com/problems/k-inverse-pairs-array/
//
//  Created by smilingpoplar on 17/12/07.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k > n * (n - 1) / 2) return 0; // 先确保k<=n*(n-1)/2
        const int MOD = 1e9+7;
        // 设dp[i][j]表示[1..i]的排列中刚好j个逆序对的排列个数。
        // 假设已解决[1..i-1]子问题，考虑新增数i。把新增数放在最后，不增加逆序对；把这数往前移x位，就增加x个逆序对。
        // 故dp[i][j] = sum{ dp[i-1][j-x] }，由0<=x<=i-1。
        // 初始dp[0..n][0]=1，dp[0][1..k]=0，特别注意dp[0][0]=1（空集也算一个排列）
        // 复杂度O(n^2*k)，超时，要优化。
        // 
        //   dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + ... + dp[i-1][j-i+1]
        // dp[i][j-1] =              dp[i-1][j-1] + ... + dp[i-1][j-i+1] + dp[i-1][j-i]
        // dp[i][j] - dp[i][j-1] = dp[i-1][j] - dp[i-1][j-i]
        //
        // 故 dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-i]
        // 考虑边界条件，当j<i时dp[i-1][j-i]不存在。
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                int val = (dp[i][j-1] + dp[i-1][j]) % MOD;
                if (j - i >= 0) val = (val - dp[i-1][j-i] + MOD) % MOD;
                dp[i][j] = val;
            }
        }
        return dp[n][k];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
