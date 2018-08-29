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
        // 设A[lo..hi]是A[..i]的 L<=所有子段元素<=R 的最新子段
        int lo = 0, hi = -1, ans = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > R) lo = i + 1;
            if (A[i] >= L) hi = i;
            // 添上A[i]构成新子段：A[lo..i], A[lo+1..i], ..., A[hi..i]
            ans += hi - lo + 1;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
