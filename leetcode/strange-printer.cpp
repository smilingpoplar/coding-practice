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
        const int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
        for (int i = 0; i < N; i++) dp[i][i] = 1;
        
        for (int len = 2; len <= N; len++) {
            for (int i = 0; i <= N - len; i++) {
                int j = i + len - 1;
                for (int k = i; k < j; k++) { // 分成两段s[i..k]、s[k+1..j]
                    int count = dp[i][k] + dp[k+1][j];
                    if (s[k] == s[j]) count--; // 两段尾字母可先同时打印，少打印一次
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
