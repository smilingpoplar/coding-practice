//
//  decode-ways
//  https://leetcode.com/problems/decode-ways/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // 设dp[i]表示s[i..]的解码数，0<=i<=N
        // 若isValid(s[i]), dp[i] += dp[i+1]；若isValid(s[i..i+1])，dp[i] += dp[i+2]
        // 初始dp[N] = 1
        const int N = s.size();
        vector<int> dp(N + 1, 0);
        dp[N] = 1;
        
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] != '0') 
                dp[i] += dp[i+1];
            if (i + 1 < N && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) 
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.numDecodings("26");

    return 0;
}
