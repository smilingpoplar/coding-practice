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
        // 设dp[i]表示s[0..i]的编码数。
        // 若s[i]单独编码：
        // s[i]    *       0    [1-9]
        //     9*dp[i-1]  xxx  dp[i-1]
        // 若s[i]和s[i-1]一起编码：
        //     s[i]    *          [0-6]     [7-9]
        // s[i-1]
        //    *    15*dp[i-2]   2*dp[i-2]  dp[i-2]
        //    1     9*dp[i-2]    dp[i-2]   dp[i-2]
        //    2     6*dp[i-2]    dp[i-2]     xxx
        //  0, 3-9     xxxxxxxxxxxxxxxxxx
        const int M = 1000000007;
        // 用long防止计算过程中溢出！仅仅赋值前每次都%M，中间变量也可能溢出导致计算错误。
        long prev2 = 1, prev1 = 1;
        for (int i = 0; i < s.size(); i++) {
            long curr = 0;
            if (s[i] == '*') {
                curr += 9 * prev1;
                if (i > 0) {
                    if (s[i-1] == '*') {
                        curr += 15 * prev2;
                    } else if (s[i-1] == '1') {
                        curr += 9 * prev2;
                    } else if (s[i-1] == '2') {
                        curr += 6 * prev2;
                    }
                }
            } else {
                if (s[i] != '0') curr += prev1;
                if (i > 0) {
                    if (s[i-1] == '*') {
                        if (s[i] <= '6') curr += 2 * prev2;
                        else curr += prev2;
                    } else if (s[i-1] == '1') {
                        curr += prev2;
                    } else if (s[i-1] == '2') {
                        if (s[i] <= '6') curr += prev2;
                    }
                }
            }
            prev2 = prev1;
            prev1 = curr % M;
        }
        return (int)prev1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
