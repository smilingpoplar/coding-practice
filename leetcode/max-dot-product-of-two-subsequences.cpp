//
//  max-dot-product-of-two-subsequences
//  https://leetcode.com/problems/max-dot-product-of-two-subsequences/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        // 设dp[i][j]表示A[..i)和B[..j)的最大非空子序列点积
        // dp[i][j] = max{ A[i-1]*B[j-1], // 子序列非空，dp[i-1][j-1]也非空
        //                 A[i-1]*B[j-1] + dp[i-1][j-1], dp[i-1][j], dp[i][j-1] }
        const int INF = 1e9;
        const int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, -INF));
        
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                int prod = A[i-1] * B[j-1];
                dp[i][j] = max({ prod, prod + dp[i-1][j-1], dp[i-1][j], dp[i][j-1] });
            }
        }
        return dp[M][N];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
