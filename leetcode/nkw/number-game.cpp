//
//  number-game
//  NC327 取数游戏
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numbergame(vector<int>& A, vector<int>& B) {
        // 设dp[i][j]表示第i次取数、左边已经取走了j个数，此时的最大价值，0<=j<=i<=N
        // dp[i][j] = max{B[i-1]*A[j-1] + dp[i-1][j-1],
        //                B[i-1]*A_{右边数第(i-j)个数} + dp[i-1][j]}
        const int N = A.size();
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= i; j++) {
                if (j < i) dp[i][j] = max(dp[i][j], B[i - 1] * A[N - (i - j)] + dp[i - 1][j]);
                if (j > 0) dp[i][j] = max(dp[i][j], B[i - 1] * A[j - 1] + dp[i - 1][j - 1]);
            }
        }

        int ans = INT_MIN;
        for (int j = 0; j <= N; j++) {
            ans = max(ans, dp[N][j]);
        }
        return ans;
    }
};