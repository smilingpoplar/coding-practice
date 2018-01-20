//
//  subarray-product-less-than-k
//  https://leetcode.com/problems/subarray-product-less-than-k/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // 因为 k<2^20, nums[i]<2^10，小于k的乘积x*nums[i]<2^30不会溢出，直接用连乘积
        if (k <= 0) return 0;
        
        int ans = 0;
        int prod = 1;
        for (int right = 0, left = 0; right < nums.size(); ++right) {
            prod *= nums[right];
            while (prod >= k && left <= right) {
                prod /= nums[left];
                ++left;
            }
            ans += right - left + 1;
        }
        return ans;
    }    
};

int main(int argc, const char * argv[]) {    
    return 0;
}
