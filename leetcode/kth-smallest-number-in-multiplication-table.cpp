//
//  kth-smallest-number-in-multiplication-table
//  https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        // 猜第k小的数x，x在范围[1..m*n]
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
        // <=x的数有count个，count(x)是关于x的递增函数，
        // count(x)>=k符合二分搜索的条件形式[0..0 1..1]
        int count = 0;
        for (int r = 1; r <= m; r++) {
            // 乘法表一行行看该行有多少乘积<=x
            count += min(x / r, n);
        }
        return count >= k;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
