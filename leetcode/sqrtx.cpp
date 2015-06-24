//
//  sqrtx
//  https://leetcode.com/problems/sqrtx/
//
//  Created by smilingpoplar on 15/6/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) return -1;
        // 牛顿迭代
        // 先随便猜一个数y，然后 y=(y+x/y)/2 迭代
        double y = 1;
        double lastY = -1;
        while ((int)y != (int)lastY) {
            lastY = y;
            y = (y + x / y) / 2;
        }
        return y;
    }
};
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) return -1;
        // 二分搜索
        // 不变式：y是满足y^2<=x的最大数，l<=y<r && l<r
        if (x <= 1) return x;
        int l = 0;
        int r = x;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (mid <= x / mid) { // mid*mid<=x可能溢出
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.mySqrt(1);
    
    return 0;
}
