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
        // 要返回无序数组中的下标，不能用先排序再左右夹逼的方法，要用map
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i + 1;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            int another = target - nums[i];
            if (map.find(another) != map.end() && map[another] > i + 1) {
                return {i + 1, map[another]};
            }
        }
        return vector<int>();
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
