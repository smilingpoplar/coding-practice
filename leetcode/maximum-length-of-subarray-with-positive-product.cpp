//
//  maximum-length-of-subarray-with-positive-product
//  https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        // 最长正乘积子段
        const int N = nums.size();
        int zeroIdx = -1, firstNegIdx = -1, countNeg = 0;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (nums[i] < 0) {
                if (firstNegIdx == -1) firstNegIdx = i;
                countNeg++;
            } else if (nums[i] == 0) {
                zeroIdx = i;
                firstNegIdx = -1;
                countNeg = 0;
            }
            ans = max(ans, countNeg % 2 ? i - firstNegIdx : i - zeroIdx);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
