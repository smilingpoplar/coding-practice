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
        // x范围[1..m*n]
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
    
    // 二分搜索需要返回[0 0 ... 0 1 1 ...]，enough(x)表示x>=第k大的数吗，
    // 故enough(x)中需要统计x是第几大的数，即统计<=x的数有多少个
    bool enough(int x, int m, int n, int k) {
        // 一行行看乘法表有多少数<=x
        int count = 0;
        for (int r = 1; r <= m; r++) {
            count += min(x / r, n);
        }
        return count >= k;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
