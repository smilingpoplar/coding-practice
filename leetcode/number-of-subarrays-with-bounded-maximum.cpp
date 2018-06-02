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
        // 设[left..right]是以A[right]结尾的 L<=子数组最大值<=R 的最长子数组
        int left = 0, right = -1, ans = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > R) left = i + 1; // 子数组中不能包含A[i]
            if (A[i] >= L) right = i;
            ans += right - left + 1;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
