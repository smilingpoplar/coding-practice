//
//  can-i-win
//  https://leetcode.com/problems/can-i-win/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canIWin(int maxInt, int desired) {
        if (maxInt >= desired) return true;
        if (maxInt * (maxInt + 1) / 2 < desired) return false;
        // 因为1<=maxInt<=20，memo需要1<<20大小
        // memo[i]：0 未计算、1 win、-1 lose
        vector<int> memo(1 << 20);
        // 把哪些数用过编码到maskUsed
        function<bool(int,int)> dp = [&](int desired, unsigned maskUsed) {
            if (desired <= 0) return false; // 对方已拿到desired
            if (memo[maskUsed] != 0) return memo[maskUsed] == 1;
            
            for (int i = 1; i <= maxInt; i++) {
                unsigned maskCur = 1 << (i - 1);
                if ((maskUsed & maskCur) == 0) { // 当前数还未用过
                    if (!dp(desired - i, maskUsed | maskCur)) {
                        memo[maskUsed] = 1;
                        return true;
                    }
                }
            }
            memo[maskUsed] = -1;
            return false;
        };
        return dp(desired, 0);
    }  
};

int main(int argc, const char * argv[]) {
    return 0;
}
