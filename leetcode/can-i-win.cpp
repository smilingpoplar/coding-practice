//
//  can-i-win
//  https://leetcode.com/problems/can-i-win/
//
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
        unordered_map<unsigned, bool> memo;
        return dfs(maxChoosableInteger, desiredTotal, 0, memo);
    }
    
    // 把哪些数用过的当前状态编码used 作为memo的键
    bool dfs(int maxChoosableInteger, int desiredTotal,
            unsigned used, unordered_map<unsigned, bool> &memo) {
        if (desiredTotal <= 0) return false; // 对方已赢
        if (memo.count(used)) return memo[used];
        
        for (int i = 1; i <= maxChoosableInteger; i++) {
            unsigned mask = 1 << i;
            if ((used & mask) == 0) { // i还未用过
                if (!dfs(maxChoosableInteger, desiredTotal - i, used | mask, memo)) { // 对方输
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
