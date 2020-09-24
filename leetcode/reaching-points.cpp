//
//  reaching-points
//  https://leetcode.com/problems/reaching-points/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // 反向考虑，tx,ty大的那个一定是和，
        // 辗转相减（辗转相除）看能否收敛到(sx,sy+k*sx)或(sx+k*sy,sy)
        while (tx > sx && ty > sy) {
            if (tx > ty) tx %= ty;
            else ty %= tx;
        }
        if (tx == sx && (ty - sy) % sx == 0) return true;
        if (ty == sy && (tx - sx) % sy == 0) return true;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
