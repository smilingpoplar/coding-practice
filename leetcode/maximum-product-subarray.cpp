//
//  maximum-product-subarray
//  https://leetcode.com/problems/maximum-product-subarray/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 因为最大乘积可能来自负负得正，所以除保留当前最大乘积，还得保留当前最小乘积
        // 设f(i)表示nums[?,i]的最大乘积，g(i)表示nums[?,i]的最小乘积，0<=i<=N-1
        // 当nums[i]>=0时，f(i) = max( f(i-1)*nums[i], nums[i] )，g(i) = min( g(i-1)*nums[i], nums[i] )
        // 当nums[i]<0时，f(i) = max( g(i-1)*nums[i], nums[i]) ), g(i) = min( f(i-1)*nums[i], nums[i] )
        // 综上，f(i) = max( f(i-1)*nums[i], nums[i], g(i-1)*nums[i] ), g(i) = min( f(i-1)*nums[i], nums[i], g(i-1)*nums[i] )
        // 递推式只依赖于前一项，在i的递增循环中可降维，设f表示nums[?,i]的最大乘积，g表示nums[?,i]的最小乘积
        // f = max( f*nums[i], nums[i], g*nums[i] ), g = min( f*nums[i], nums[i], g*nums[i] )
        const int N = (int)nums.size();
        int maxProduct = INT_MIN;
        int f = 1;
        int g = 1;
        for (int i = 0; i < N; i++) {
            int tmpF = f * nums[i];
            int tmpG = g * nums[i];
            f = max({tmpF, nums[i], tmpG});
            g = min({tmpF, nums[i], tmpG});
            if (f > maxProduct) maxProduct = f;
        }
        return maxProduct;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-4,-3};
    Solution solution;
    cout << solution.maxProduct(nums);
    
    return 0;
}
