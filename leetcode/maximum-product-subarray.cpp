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
        // 最大乘积可能来自负负得正，因此要同时保留最大乘积imax和最小乘积imin。
        // 以nums[i]结尾子问题nums[0..i]的imax、imin来自 { imax*nums[i], imin*nums[i], nums[i] }
        const int N = nums.size();
        int ans = INT_MIN;
        int imax = 1, imin = 1;
        for (int num : nums) {
            int cand1 = imax * num, cand2 = imin * num;
            imax = max({cand1, cand2, num});
            imin = min({cand1, cand2, num});
            if (imax > ans) ans = imax;
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
