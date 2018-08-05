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
        // 因为最大乘积可能来自负负得正，所以除了保留当前最大乘积f[i]，还要保留当前最小乘积g[i]
        // 设f[i]表示以i结尾的nums[..i]的最大乘积，g(i)表示以i结尾的nums[..i]的最小乘积，0<=i<N
        // 当nums[i]>=0时，f[i] = max( f[i-1]*nums[i], nums[i] )，g[i] = min( g[i-1]*nums[i], nums[i] )
        // 当nums[i]<0时， f[i] = max( g(i-1]*nums[i], nums[i] )，g[i] = min( f[i-1]*nums[i], nums[i] )
        // 综上，f[i] = max( f[i-1]*nums[i], nums[i], g[i-1]*nums[i] ), 
        // g[i] = min( f[i-1]*nums[i], nums[i], g[i-1]*nums[i] )
        // 在i维上只依赖于i-1项，可省掉i维，i仍从左到右遍历，
        // f = max( f*nums[i], nums[i], g*nums[i] ), g = min( f*nums[i], nums[i], g*nums[i] )
        const int N = nums.size();
        int ans = INT_MIN;
        int f = 1, g = 1;
        for (int num : nums) {
            int tmpF = f * num;
            int tmpG = g * num;
            f = max({tmpF, num, tmpG});
            g = min({tmpF, num, tmpG});
            if (f > ans) ans = f;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-4,-3};
    Solution solution;
    cout << solution.maxProduct(nums);
    
    return 0;
}
