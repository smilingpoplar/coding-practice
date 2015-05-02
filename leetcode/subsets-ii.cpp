//
//  subsets-ii.cpp
//  https://leetcode.com/problems/subsets-ii/
//
//  Created by smilingpoplar on 15/5/2.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        subsetsWithDup(0, nums, subset, result);
        return result;
    }
private:
    
    // 某元素重复dup次，相当于可以选择该元素[0,dup]次
    void subsetsWithDup(size_t start, const vector<int> &nums, vector<int> &subset, vector<vector<int>> &result) {
        const size_t N = nums.size();
        if (start == N) {
            result.push_back(subset);
            return;
        }
        
        size_t dup = 1;
        while (start + dup < N && nums[start + dup] == nums[start]) dup++;
        
        for (size_t i = 0; i <= dup; i++) {
            for (size_t j = 0; j < i; j++) {
                subset.push_back(nums[start]);
            }
            subsetsWithDup(start + dup, nums, subset, result);
            for (size_t j = 0; j < i; j++) {
                subset.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 2};
    Solution solution;
    auto subsets = solution.subsetsWithDup(nums);
    for (const auto &subset: subsets) {
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
