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
        // 用dp[i][L]记录从i开始长为L的子串的最短编码
        const int N = s.size();
        vector<vector<string>> dp(N, vector<string>(N + 1));
        for (int L = 1; L <= N; L++) {
            for (int i = 0; i + L - 1 < N; i++) {
                dp[i][L] = collapse(s.substr(i, L), dp[i]);
                for (int k = 1; k < L; k++) { // L长分两段，第一段长k
                    if (dp[i][k].size() + dp[i+k][L-k].size() < dp[i][L].size()) {
                        dp[i][L] = dp[i][k] + dp[i+k][L-k];
                    }
                }
            }
        }
        return dp[0][N];
    }
    
    string collapse(const string &s, vector<string> &dpi) {
        int found = (s + s).find(s, 1), L = s.size();
        if (found < L) { // s=k*pattern
            auto encoded = to_string(L / found) + "[" + dpi[found] + "]"; // dp[i][found]是子问题最优解
            if (encoded.size() < L) return encoded;
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
