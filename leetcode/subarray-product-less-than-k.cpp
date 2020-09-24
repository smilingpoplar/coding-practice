//
//  subarray-product-less-than-k
//  https://leetcode.com/problems/subarray-product-less-than-k/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // 因为 k<2^20, nums[i]<2^10，小于k的乘积prod*nums[i]<2^30不会溢出
        if (k <= 1) return 0;
        
        int prod = 1, ans = 0;
        for (int hi = 0, lo = 0; hi < nums.size(); hi++) {
            prod *= nums[hi];
            while (prod >= k) {
                prod /= nums[lo];
                lo++;
            }
            // 以hi结尾的子段积都满足：[lo..hi], [lo+1,hi], ..., [hi,hi]
            ans += hi - lo + 1;
        }
        return ans;
    }    
};

int main(int argc, const char * argv[]) {    
    return 0;
}
