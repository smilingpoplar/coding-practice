//
//  can-i-win
//  https://leetcode.com/problems/can-i-win/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        unordered_map<int, bool> memo;
        return winnable(maxChoosableInteger, desiredTotal, 0, memo);
    }
    
    bool winnable(int maxChoosableInteger, int desiredTotal,
                  int used, unordered_map<int, bool> &memo) {
        if (desiredTotal <= 0) return false; // 对方已赢
        if (memo.find(used) != memo.end()) return memo[used];
        for (int i = 1; i <= maxChoosableInteger; i++) {
            if ((used & 1 << i) == 0) { // 可选择i
                if (!winnable(maxChoosableInteger, desiredTotal - i, used | 1 << i, memo)) {
                    memo[used] = true;
                    return true;
                }
            }
        }
        memo[used] = false;
        return memo[used];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
