//
//  flip-game-ii
//  https://leetcode.com/problems/flip-game-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
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
                bool winning = canWin(s, memo);
                s[i] = s[i+1] = '+';
                if (!winning) return true;
            }
        }
        memo[s] = false;
        return false;

    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
