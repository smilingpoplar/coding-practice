//
//  reaching-points
//  https://leetcode.com/problems/reaching-points/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // 反向考虑，tx,ty大的那个一定是和，辗转相减得小的那个
        while (tx > sx && ty > sy) {
            if (tx > ty) tx %= ty;
            else ty %= tx;
        }
        // tx==sx，ty只能每次再减小tx
        if (tx == sx && (ty - sy) % tx == 0) return true;
        // ty==sy，tx只能每次再减小ty
        if (ty == sy && (tx - sx) % ty == 0) return true;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
