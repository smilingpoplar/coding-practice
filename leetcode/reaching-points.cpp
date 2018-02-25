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
        // 正向考虑的话，(x,y)=>(x+y,y)或(x,x+y)，两条路径
        // 反向考虑的话，大的那个一定是和，x>=y时 (x,y)=>(x-y, y)，x<y时 (x,y)=>(x,y-x)，一条路径
        // 不断相减就是求gcd时的辗转相除
        while (tx >= sx && ty >= sy) {
            if (tx >= ty) {
                if (ty > sy) { tx %= ty; }
                else { // ty == sy，ty不能再减小，只能tx每次减小ty
                    return (tx - sx) % ty == 0;
                }
            } else {
                if (tx > sx) { ty %= tx; }
                else { // tx == sx，tx不能再减小，只能ty每次减小tx
                    return (ty - sy) % tx == 0;
                }
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
