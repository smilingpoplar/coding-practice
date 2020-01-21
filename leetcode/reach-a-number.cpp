//
//  reach-a-number
//  https://leetcode.com/problems/reach-a-number/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        // target<0往数轴左侧和target>0往数轴右侧情况对称
        target = abs(target);
        // 给1,2,...,k中一些数加上负号，设要加正号的和为A，要加负号的和为B
        // A+B=1+2+...+k=sum，A-B=target，B=(sum-target)/2
        // 要满足sum>=target且sum-target为偶数
        int sum = 0, k = 0;
        while (sum < target) 
            sum += ++k;
        int delta = sum - target;
        if (delta % 2 == 0) return k;
        // 最多再走两步，sum-target总能变成偶数
        // 走两步，是因为第一次加的k可能是偶数
        delta += ++k;
        if (delta % 2 == 0) return k;
        return k + 1 ;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
