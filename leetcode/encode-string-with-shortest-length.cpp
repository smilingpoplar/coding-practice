//
//  encode-string-with-shortest-length
//  https://leetcode.com/problems/encode-string-with-shortest-length/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string encode(string s) {
        // 用dp[i][L]记录s[i,i+L)的最短编码串
        const int N = s.size();
        vector<vector<string>> dp(N, vector<string>(N + 1)); // dp[i][0]=""
        for (int L = 1; L <= N; L++) {
            for (int i = 0; i + L <= N; i++) {
                dp[i][L] = collapse(s.substr(i, L), dp[i]); // 尝试pattern*k模式
                for (int k = 1; k < L; k++) { // 尝试分两段，第一段长k
                    if (dp[i][k].size() + dp[i+k][L-k].size() < dp[i][L].size()) {
                        dp[i][L] = dp[i][k] + dp[i+k][L-k];
                    }
                }
            }
        }
        return dp[0][N];
    }
    
    // si是s[i,i+L)子串，要看si有没有更短编码串，dpi是dp[i][<L]
    string collapse(const string &si, vector<string> &dpi) {
        int d = (si + si).find(si, 1), L = si.size();
        if (d < L) { // si=pattern*k
            auto encoded = to_string(L / d) + "[" + dpi[d] + "]"; // dp[i][d]是子问题最优解
            if (encoded.size() < L) return encoded;
        }
        return si;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
