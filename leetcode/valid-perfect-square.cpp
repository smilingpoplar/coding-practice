//
//  valid-perfect-square
//  https://leetcode.com/problems/valid-perfect-square/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        // 找到使x*x>=num的第一个x，二分搜索
        int l = 1, u = num;
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (mid >= num / mid) { // mid*mid >= num
                u = mid - 1;
            } else {
                l= mid + 1;
            }
        }
        return l * l == num;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
