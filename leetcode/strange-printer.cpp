//
//  strange-printer
//  https://leetcode.com/problems/strange-printer/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        // 设dp[i][j]表示s[i..j]的最少打印数，
        // 尝试将[i..j]分成两段[i..k]、[k+1..j]，i<=k<j，比较两段末尾
        // 若s[k]==s[j]，j可以在打印k时一起打印，
        // dp[i][j] = min{ dp[i][k]+dp[k+1][j-1] }（这里要k+1<=j-1）
        // 若所有s[k]和s[j]都不相等，dp[i][j] = dp[i][j-1]+1
        // 初始dp[i][i]=1。i从右往左遍历，j从左往右遍历。
        const int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
        for (int i = 0; i < N; i++) {
            dp[i][i] = 1;
        }
        
        for (int i = N - 1; i >= 0; i--) {
            for (int j = i + 1; j < N; j++) {
                dp[i][j] = dp[i][j-1] + 1; // 所有s[k]和s[j]都不相等
                for (int k = i; k < j; k++) {
                    if (s[k] == s[j]) {
                        int part = k+1 <= j-1 ? dp[k+1][j-1] : 0;
                        dp[i][j] = min(dp[i][j], dp[i][k] + part);
                    }
                }
            }
        }
        return dp[0][N-1];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
