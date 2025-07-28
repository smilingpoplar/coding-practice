//
//  maximum-sum-circular-subarray
//  https://leetcode.com/problems/maximum-sum-circular-subarray/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        // 1. 没跨越数组尾，= 最大子段和ansMax
        // 2. 跨越数组尾，= arrSum - 最小子段和ansMin
        // 特例：ansMax<0时，数组全是负数，arrSum==ansMin；要返回ansMax
        int currMax = 0, ansMax = INT_MIN;
        int currMin = 0, ansMin = INT_MAX;
        int arrSum = 0;
        for (int a : A) {
            currMax = a + max(currMax, 0);  // 非空子段
            ansMax = max(ansMax, currMax);
            currMin = a + min(currMin, 0);
            ansMin = min(ansMin, currMin);
            arrSum += a;
        }
        if (ansMax < 0) return ansMax;
        return max(ansMax, arrSum - ansMin);
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
