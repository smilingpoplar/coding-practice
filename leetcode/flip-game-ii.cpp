//
//  flip-game-ii
//  https://leetcode.com/problems/flip-game-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canWin(string s) {
        unordered_map<string, bool> memo; // s=>winOrNot
        return canWin(s, memo);
    }
    
    bool canWin(string &s, unordered_map<string, bool> &memo) {
        if (memo.count(s)) return memo[s];
        // 回溯法
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] == '+' && s[i+1] == '+') {
                s[i] = s[i+1] = '-';
                bool player2 = canWin(s, memo);
                s[i] = s[i+1] = '+';
                if (!player2) {
                    memo[s] = true;
                    return memo[s];
                }
            }
        }
        memo[s] = false;
        return memo[s];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
