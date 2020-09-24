//
//  broken-calculator
//  https://leetcode.com/problems/broken-calculator/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        // 反过来从Y变为X，支持两种操作：1. Y/=2  2. Y++
        // 若Y<X，只能不断Y++；若Y>X，为使Y尽快变小，
        // Y为偶数时Y/=2，Y为奇数时Y++（下一轮就能除以2）。
        int ans = 0;
        while (Y > X) {
            Y = (Y % 2 == 0) ? Y / 2 : Y + 1;
            ans++;
        }
        ans += X - Y;
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
