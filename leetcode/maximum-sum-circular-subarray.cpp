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
        // 2. 跨越数组尾时的最大子段和 = 总和-数组中段的minSubarraySum，
        //    minSubarray不能扩展为全数组，否则跨越数组尾的子段为空，这需要minSubarraySum!=totalSum
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
        if (ansMin == totalSum) return ansMax;
        return max(ansMax, totalSum - ansMin);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
