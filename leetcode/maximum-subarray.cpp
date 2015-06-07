//
//  maximum-subarray
//  https://leetcode.com/problems/maximum-subarray/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 设f(i)表示nums[?,i]的最大和，则 f(i) = max( f(i-1)+nums[i], nums[i] )
        // 递推式只依赖于前一项，在i的递增循环中降维，设f表示nums[?,i]的最大和，则 f = max( f+nums[i], nums[i] )
        int maxSum = INT_MIN;
        int f = 0;
        for (int i = 0; i < nums.size(); ++i) {
            f = max(f + nums[i], nums[i]);
            if (f > maxSum) maxSum = f;
        }
        return maxSum;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solution;
    cout << solution.maxSubArray(nums);
    
    return 0;
}
