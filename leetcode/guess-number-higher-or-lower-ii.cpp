//
//  guess-number-higher-or-lower-ii
//  https://leetcode.com/problems/guess-number-higher-or-lower-ii/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        // 设dp[i][j]表示[i..j]子问题保证赢需要多少钱，1<=i<=j<=n
        // dp[i][j]=min{ k+max(dp[i][k-1],dp[k+1][j]) }，i<=k<=j
        // k+max(dp[i][k-1],dp[k+1][j])表示猜k保证赢需要多少钱，
        // dp[i][j]=min{...}表示所有保证赢的情况里最少需要多少钱。
        // 初始dp[i][i]=0
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0)); // dp[0]、dp[n+1]前后哨兵
        for (int i = 1; i <= n; i++) dp[i][i] = 0;
        
        for (int len = 2; len <= n; len++) {
            for (int i = 1, j = i + len - 1; j <= n; i++, j++) {
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; k++) {
                    int money = k + max(dp[i][k-1], dp[k+1][j]);
                    dp[i][j] = min(dp[i][j], money);
                }                
            }
        }
        return dp[1][n];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
