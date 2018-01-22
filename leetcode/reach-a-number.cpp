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
        // 给1,2,...,k中一些数加上负号，要加正号的数和为A，要加负号的数和为B
        // A+B=S=1+2+...+k，A-B=target，B=(S-target)/2，S-target为偶数时B存在
        // 先让S>=target
        target = abs(target);
        int sum = 0;
        int k = 0;
        while (sum < target) 
            sum += ++k;
        int delta = sum - target;
        if (delta % 2 == 0) return k;
        // 否则最多再加两次k
        delta += ++k;
        if (delta % 2 == 0) return k;
        return k + 1 ;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
