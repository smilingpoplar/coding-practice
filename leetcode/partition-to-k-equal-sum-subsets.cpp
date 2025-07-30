//
//  partition-to-k-equal-sum-subsets
//  https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        const int N = nums.size();
        if (N < k) return false;
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % k != 0) return false;

        vector<bool> seen(N, false);
        return search(nums, 0, seen, k, 0, sum / k);
    }

    // 从nums[idx..]取数，还要分割k个子集，当前子集已累积和subSum
    bool search(vector<int> &nums, int idx, vector<bool> &seen, int k, int subSum, int target) {
        if (k == 0) return true;
        if (subSum == target) return search(nums, 0, seen, k - 1, 0, target);

        for (int i = idx; i < nums.size(); i++) {
            if (seen[i] || subSum + nums[i] > target) continue;

            seen[i] = true;
            if (search(nums, i + 1, seen, k, subSum + nums[i], target)) return true;
            seen[i] = false;
        }
        return false;
    }
};
