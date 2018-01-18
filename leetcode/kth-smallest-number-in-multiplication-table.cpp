//
//  kth-smallest-number-in-multiplication-table
//  https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
//
//  Created by smilingpoplar on 18/01/18.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        // 找出第一个满足enough()的x，l<x<=u
        int l = 0, u = m * n + 1;
        while (l + 1 < u) {
            int mid = l + (u - l) / 2;
            if (enough(mid, m, n, k)) {
                u = mid;
            } else {
                l = mid;
            }
        }
        return u;
    }
    
    bool enough(int x, int m, int n, int k) {
        // 算x是第几大，一行行看乘法表有多少数小于等于它
        int count = 0;
        for (int r = 1; r <= m; ++r) {
            count += min(x / r, n);
        }
        return count >= k;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
