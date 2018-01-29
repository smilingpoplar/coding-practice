//
//  matchsticks-to-square
//  https://leetcode.com/problems/matchsticks-to-square/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % 4 != 0) return false;
        
        vector<int> subsets(4, 0);
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(nums, 0, subsets, sum / 4);
    }
    
    bool dfs(vector<int> &nums, int idx, vector<int> &subsets, int target) {
        if (idx == nums.size()) {
            for (int subset : subsets) {
                if (subset != target) return false;
            }
            return true;
        }
        
        for (int &subset : subsets) {
            if (subset + nums[idx] > target) continue;
            subset += nums[idx];
            if (dfs(nums, idx + 1, subsets, target)) return true;
            subset -= nums[idx];
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
