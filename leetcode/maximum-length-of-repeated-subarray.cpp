//
//  maximum-length-of-repeated-subarray
//  https://leetcode.com/problems/maximum-length-of-repeated-subarray/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        // 设dp[i][j]表示以A[i]开头的A[i..]、以B[j]开头的B[j..]的最长公共子段长
        // 若A[i]==B[j]，dp[i][j]=1+dp[i+1][j+1]；否则，dp[i][j]=0
        // 初始dp[M][j]=0，dp[i][N]=0
        const int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        int ans = 0;
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (A[i] == B[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
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
