//
//  grumpy-bookstore-owner
//  https://leetcode.com/problems/grumpy-bookstore-owner/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        // 滑动窗口记录X分钟内的不满意者xUnsatis
        const int N = customers.size();
        int satis = 0, xUnsatis = 0, maxUnsatis = 0;
        for (int hi = 0; hi < N; hi++) {
            if (!grumpy[hi]) satis += customers[hi];
            if (grumpy[hi]) xUnsatis += customers[hi];
            if (hi >= X && grumpy[hi-X]) xUnsatis -= customers[hi-X];
            maxUnsatis = max(maxUnsatis, xUnsatis);
        }
        return satis + maxUnsatis;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
