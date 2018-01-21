//
//  maximum-length-of-repeated-subarray
//  https://leetcode.com/problems/maximum-length-of-repeated-subarray/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        // 设dp[i][j]表示A[0..i-1]以A[i-1]结尾、B[0..j-1]以B[j-1]结尾的最长公共子数组的长度
        // 如果A[i-1]==B[j-1]，dp[i][j]=1+dp[i-1][j-1]；否则dp[i][j]=0
        // 初始dp[0][j]=0，dp[i][0]=0
        const int M = A.size();
        const int N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        int ans = 0;
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
