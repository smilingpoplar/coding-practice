//
//  elimination-game
//  https://leetcode.com/problems/elimination-game/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        // n是奇数或从左到右删，head前进一个step；否则，head不变
        // 比如：
        // 1 2 3 4 5 6 7 8 9
        //   2   4   6   8
        //   2       6
        //           6
        int head = 1, remaining = n, step = 1;
        bool fromLeft = true;
        while (remaining > 1) {
            if (remaining % 2 == 1 || fromLeft) head += step;
            remaining /= 2;
            step *= 2;
            fromLeft = !fromLeft;
        }
        return head;
    }    
};

int main(int argc, const char * argv[]) {
    return 0;
}
