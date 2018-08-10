//
//  decode-ways-ii
//  https://leetcode.com/problems/decode-ways-ii/
//
//  Created by smilingpoplar on 17/12/08.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // 设dp[i]表示s[i..]的解码数
        // 若isValid(s[i..i]), dp[i] += ??dp[i+1]；若isValid(s[i,i+1])，dp[i] += ??dp[i+2]
        // 若s[i]单独解码：
        // s[i]
        //   *     9*dp[i+1]
        //   0      xxx
        // [1-9]    dp[i+1]
        // 若s[i]和s[i+1]一起解码：
        //     s[i+1]    *          [0-6]     [7-9]
        // s[i]
        //   *      15*dp[i+2]   2*dp[i+2]  dp[i+2]
        //   1       9*dp[i+2]    dp[i+2]   dp[i+2]
        //   2       6*dp[i+2]    dp[i+2]     xxx
        //  0, 3-9     xxxxxxxxxxxxxxxxxx
        const int Mod = 1e9 + 7;
        // 用long防止计算过程中溢出！
        // 若用int且右端%M，中间变量也可能溢出导致错误。
        const int N = s.size();
        long next1 = 1, next2 = 1;
        for (int i = N; i >= 0; i--) {
            long curr = 0;
            if (s[i] == '*') {
                curr += 9 * next1;
                if (i + 1 < N) {
                    if (s[i+1] == '*') curr += 15 * next2;
                    else if (s[i+1] <= '6') curr += 2 * next2;
                    else curr += next2;
                }
            } else {
                if (s[i] != '0') curr += next1;
                if (i + 1 < N) {
                    if (s[i] == '1') {
                        if (s[i+1] == '*') curr += 9 * next2;
                        else curr += next2;
                    } else if (s[i] == '2') {
                        if (s[i+1] == '*') curr += 6 * next2;
                        else if (s[i+1] <= '6') curr += next2;
                    }
                }
            }
            next2 = next1;
            next1 = curr % Mod;
        }
        return (int)next1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
