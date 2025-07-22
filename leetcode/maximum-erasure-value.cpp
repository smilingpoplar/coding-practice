//
//  maximum-erasure-value
//  https://leetcode.com/problems/maximum-erasure-value/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // 滑动窗口
        int sum = 0, ans = INT_MIN;
        unordered_set<int> seen;
        for (int hi = 0, lo = 0; hi < nums.size(); hi++) {
            while (seen.count(nums[hi])) {
                seen.erase(nums[lo]);
                sum -= nums[lo];
                lo++;
            }
            seen.insert(nums[hi]);
            sum += nums[hi];
            ans = max(ans, sum);
        }

        return ans;
    }
};