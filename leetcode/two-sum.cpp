//
//  two-sum
//  https://leetcode.com/problems/two-sum/
//
//  Created by smilingpoplar on 15/5/10.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return {};
        unordered_map<int, int> mp;
        mp[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++) {
            int toFind = target - nums[i];
            if (mp.find(toFind) != mp.end()) {
                return { mp[toFind], i };
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {3, 2, 4};
    int target = 6;
    Solution solution;
    auto result = solution.twoSum(nums, target);
    for (int index : result) {
        cout << index << " ";
    }
    
    return 0;
}
