//
//  number-of-subarrays-with-bounded-maximum
//  https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        // 题目：求满足 L<= 子段最大值 <=R 的子段数
        // 从左往右，统计以A[i]结尾的有效子段数
        //  例如 A=[0,1,2,-1], L=2, R=3
        //   i=0时，无；i=1时，无；i=2时，三个以2结尾的有效子段：[0,1,2], [1,2], [2]；
        //   i=3时，和i=2的情况相同，三个以-1结尾的有效子段：[0,1,2,-1], [1,2,-1], [2,-1]
        //
        // 设[lo..hi]是有效子段起始的范围，ans += hi-lo+1
        //  若L<=A[i]<=R，hi=i；
        //  若A[i]>R，lo=i+1，hi=i；
        //  若A[i]<L，lo和hi不变
        int ans = 0;
        int lo = 0, hi = -1;
        for (int i = 0; i < A.size(); i++) {
            if (L <= A[i] && A[i] <= R) {
                hi = i;
            } else if (A[i] > R) {
                lo = i + 1, hi = i;
            }
            ans += hi - lo + 1;  // A[lo..i], A[lo+1..i], ..., A[hi..i]
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
