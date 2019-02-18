//
//  number-of-subarrays-with-bounded-maximum
//  https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        // 求满足 L<= 子段最大值 <=R 的子段数
        // 维持不变式：L<= 子段A[lo..hi]中所有值 <=R
        int lo = 0, hi = -1;
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            if (L <= A[i] && A[i] <= R) {
                hi = i;
            } else if (A[i] > R) {
                lo = i + 1, hi = i;
            } // else：A[i] < L，A[i]并入前一子段
            ans += hi - lo + 1; // A[lo..i], A[lo+1..i], ..., A[hi..i]
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
