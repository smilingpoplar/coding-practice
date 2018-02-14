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
        vector<vector<int>> ans;
        vector<int> subset;
        search(nums, 0, subset, ans);
        return ans;
    }

    void search(const vector<int> &nums, int idx,
                vector<int> &subset, vector<vector<int>> &ans) {
        ans.push_back(subset);
        
        for (int i = idx; i < nums.size(); i++) {
            // 排除重复的组合：某数字选中的递归情况不用管，一旦不选则后面相同数字都不选
            if (i > idx && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            search(nums, i + 1, subset, ans);
            subset.pop_back();
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
