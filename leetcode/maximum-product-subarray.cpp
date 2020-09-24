//
//  maximum-product-subarray
//  https://leetcode.com/problems/maximum-product-subarray/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 最大乘积可能来自负负得正，因此要保留最大乘积currMax和最小乘积currMin，
        // 以nums[i]结尾子问题nums[0..i]的最大最小乘积来自 { currMax*nums[i], currMin*nums[i], nums[i] }
        const int N = nums.size();
        int currMax = 1, currMin = 1, ans = INT_MIN;
        for (int num : nums) {
            int cand1 = currMax * num, cand2 = currMin * num;
            currMax = max({cand1, cand2, num});
            currMin = min({cand1, cand2, num});
            if (currMax > ans) ans = currMax;
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
