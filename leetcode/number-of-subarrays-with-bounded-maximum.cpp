//
//  number-of-subarrays-with-bounded-maximum
//  https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        // 求满足 L<= 子段最大值 <=R 的子段数
        //
        // 每次循环看以A[i]结尾的有效子段，例如 A=[0,1,2,-1], L=2, R=3
        //  i=0时，无；i=1时，无；i=2时，三个以2结尾的有效子段：[0,1,2], [1,2], [2]；
        //  i=3时，和i=2的情况相同，三个以-1结尾的有效子段：[0,1,2,-1], [1,2,-1], [2,-1]
        //
        // 每次循环，A[i]是有效子段的结尾，设[lo1..lo2]是有效子段起始的范围，ans += lo2-lo1+1
        //  若L<=A[i]<=R，lo2=i；
        //  若A[i]>R，lo1=i+1，lo2=i；
        //  若A[i]<L，lo1和lo2不变
        int ans = 0;
        int lo1 = 0, lo2 = -1;
        for (int i = 0; i < A.size(); i++) {
            if (L <= A[i] && A[i] <= R) {
                lo2 = i;
            } else if (A[i] > R) {
                lo1 = i + 1, lo2 = i;
            }
            ans += lo2 - lo1 + 1; // A[lo1..i], A[lo1+1..i], ..., A[lo2..i]
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
