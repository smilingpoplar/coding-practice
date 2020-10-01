//
//  stone-game-iv
//  https://leetcode.com/problems/stone-game-iv/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        // 每次移出平方数个石头
        // 设dp[i]表示i个石头时能否赢，dp[i]=any{ !dp[i-squreNum] }
        vector<bool> dp(n + 1); // dp[0]==false
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k * k <= i; k++) {
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
