//
//  strange-printer
//  https://leetcode.com/problems/strange-printer/
//
//  Created by smilingpoplar on 18/01/18.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        // 设dp[i][j]表示s[i..j]的最少打印数。看i<=k<=j的k处，
        // 当k==i，dp[i][j]=1+dp[i+1][j]
        // 当i<k<=j，dp[i][j]=dp[i][k]+dp[k+1][j]；
        //  若s[i]==s[k]，k可以和i一起打印，dp[i][k]=dp[i][k-1]
        // 初始i==j时，dp[i][i]=1
        // i从右往左遍历，j从左往右遍历
        const int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
        for (int i = 0; i < N; i++) {
            dp[i][i] = 1;
        }
        
        for (int i = N - 2; i >= 0; i--) {
            for (int j = i + 1; j < N; j++) {
                for (int k = i; k <= j; k++) {
                    int count = (k+1 <= j) ? dp[k+1][j] : 0;
                    if (k == i) count += 1;
                    else {
                        if (s[i] == s[k]) count += (i <= k-1) ? dp[i][k-1] : 0;
                        else count += dp[i][k];
                    }
                    dp[i][j] = min(dp[i][j], count);
                }
            }
        }
        return dp[0][N-1];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
