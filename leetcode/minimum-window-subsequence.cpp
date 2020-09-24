//
//  minimum-window-subsequence
//  https://leetcode.com/problems/minimum-window-subsequence/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        // 设dp[i][j]=k表示在S[0..i)中找T[0..j)子序列、找到的最右起始索引（最右=>最小窗口），
        // 找到时S[k..i)是包含T[0..j)的最小窗口，找不到时k==-1。
        // 若S[i-1]==T[j-1]，需在S[0..i-1)中找T[0..j-1)，dp[i][j]=dp[i-1][j-1]
        // 若S[i-1]!=T[j-1]，需在S[0..i-1)中找T[0..j)，dp[i][j]=dp[i-1][j]
        // 所以 dp[i][j] = (S[i-1]==T[j-1]) ? dp[i-1][j-1] : dp[i-1][j]
        // 初始时dp[i][0]=i /*S[k..i)为空串*/, dp[0][j>0]=-1。
        const int M = S.size(), N = T.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, -1));
        for (int i = 0; i <= M; i++) dp[i][0] = i;

        int minlen = INT_MAX, start = -1;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = (S[i-1] == T[j-1]) ? dp[i-1][j-1] : dp[i-1][j];
            }
            
            if (dp[i][N] != -1) { // [dp[i][N]..i)包含T
                int len = i - dp[i][N];
                if (len < minlen) { // 多个解取最左的
                    minlen = len;
                    start = dp[i][N];
                }
            }
        }
        return (minlen == INT_MAX) ? "" : S.substr(start, minlen);        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
