//
//  valid-permutations-for-di-sequence
//  https://leetcode.com/problems/valid-permutations-for-di-sequence/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numPermsDISequence(string S) {
        // 设dp[i][j]表示[0..i]的排列、结尾是j时的DI排列数
        // dp[i][j]与子问题dp[i-1][]有什么关系？
        // 考虑某排列（如201），它跟更长1的、分别以0,1,2,3结尾的排列（3120,3021,3012,2013）
        // 可以建立一一映射：
        //   比如在201后添上结尾0（2010），然后把结尾左边>=结尾0的全加上1（变成3120）；
        //   或3012去掉结尾2（301），然后把>=结尾2的全减去1（变成201）。
        // 每个排列，都可以跟更长1的排列这么一一映射。
        // 故遇D结尾下降时，dp[i][j]=sum(dp[i-1][j..i-1])
        //   sum要从dp[i-1][j]开始，比如201添结尾1变成3021，结尾下降，dp[2][1]变成dp[3][1]一部分
        //   遇I结尾上升时，dp[i][j]=sum(dp[i-1][0..j-1])
        // 初始dp[0][]=1
        
        const int MOD = 1e9 + 7;
        const int N = S.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
        for (int j = 0; j <= N; j++) dp[0][j] = 1;
        
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= i; j++) {
                long sum = 0;
                if (S[i-1] == 'D') {
                    for (int k = j; k <= i - 1; k++) {
                        sum = (sum + dp[i-1][k]) % MOD;
                    }
                } else {
                    for (int k = 0; k <= j - 1; k++) {
                        sum = (sum + dp[i-1][k]) % MOD;
                    }
                }
                dp[i][j] = sum;
            }
        }
        
        long ans = 0;
        for (int j = 0; j <= N; j++)
            ans = (ans + dp[N][j]) % MOD;
        return ans;
     }
};

int main(int argc, const char * argv[]) {
    return 0;
}
