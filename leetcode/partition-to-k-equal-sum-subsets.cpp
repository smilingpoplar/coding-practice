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
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % k != 0) return false;
        
        vector<int> subsetSums(k, 0);
        return search(nums, 0, subsetSums, sum / k);
    }
    
    bool search(vector<int> &nums, int idx, vector<int> &subsetSums, int targetSum) {
        if (idx == nums.size()) {
            for (int j = 0; j < subsetSums.size(); j++) {
                if (subsetSums[j] != targetSum) return false;
            }
            return true;
        }
        
        for (int j = 0; j < subsetSums.size(); j++) {
            if (subsetSums[j] + nums[idx] > targetSum) continue;
            subsetSums[j] += nums[idx];
            if (search(nums, idx + 1, subsetSums, targetSum)) return true;
            subsetSums[j] -= nums[idx];
            if (subsetSums[j] == 0) break; // 剪枝：subsetSums初始全是0，第一个0试过不行，后面的0不用再试
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
