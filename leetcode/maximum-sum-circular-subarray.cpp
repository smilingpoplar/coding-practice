//
//  maximum-sum-circular-subarray
//  https://leetcode.com/problems/maximum-sum-circular-subarray/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        // 1. 没跨越数组尾时是maxSubarraySum问题
        // 2. 跨越数组尾时的最大子段和 = 全数组总和 - 数组中段的minSubarraySum
        // 特例是数组全为负数，这时ansMax<0，应返回ansMax
        int currMax = 0, ansMax = INT_MIN;
        int currMin = 0, ansMin = INT_MAX;
        int totalSum = 0;
        for (int a : A) {
            currMax = a + max(currMax, 0);
            ansMax = max(ansMax, currMax);
            currMin = a + min(currMin, 0);
            ansMin = min(ansMin, currMin);
            totalSum += a;
        }
        if (ansMax < 0) return ansMax;
        return max(ansMax, totalSum - ansMin);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
