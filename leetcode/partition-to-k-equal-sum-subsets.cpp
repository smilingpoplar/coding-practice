//
//  partition-to-k-equal-sum-subsets
//  https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size() < k) return false;
        int sum = 0;
        for (int num : nums) 
            sum += num;
        if (sum % k != 0) return false;
        
        vector<int> subsets(k, 0);
        sort(nums.begin(), nums.end(), greater<int>()); // 大的先选能更快判断
        return search(nums, 0, subsets, sum / k);
    }
    
    bool search(vector<int> &nums, int idx, vector<int> &subsets, int target) {
        if (idx == nums.size()) {
            for (int subset : subsets) {
                if (subset != target) return false;                
            }
            return true;
        }
        
        for (int &subset : subsets) {
            if (subset + nums[idx] > target) continue;
            subset += nums[idx];
            if (search(nums, idx + 1, subsets, target)) return true;
            subset -= nums[idx];
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
