//
//  partition-to-k-equal-sum-subsets
//  https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
//
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
        
        vector<bool> visited(nums.size(), false);
        return search(nums, 0, visited, k, 0, sum / k);
    }
    
    // 从nums[idx..]取数，还要分割k个子集，当前子集已累积和subSum
    bool search(vector<int> &nums, int idx, vector<bool> &visited, int k, int subSum, int target) {
        if (k == 1) return true; // 前面k-1个子集和都是sum/k，最后1个肯定也是sum/k
        if (subSum == target) return search(nums, 0, visited, k - 1, 0, target);
        
        for (int i = idx; i < nums.size(); i++) {
            if (visited[i] || subSum + nums[i] > target) continue;

            visited[i] = true;
            if (search(nums, i + 1, visited, k, subSum + nums[i], target)) return true;
            visited[i] = false;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
