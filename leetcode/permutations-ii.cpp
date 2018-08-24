//
//  permutations-ii
//  https://leetcode.com/problems/permutations-ii/
//
//  Created by smilingpoplar on 15/5/28.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        search(nums, 0, ans);
        return ans;
    }

    void search(vector<int> &nums, int idx, vector<vector<int>> &ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // 有重复元素，相同元素只选第一个；不能排序数组
        unordered_set<int> seen;
        for (int i = idx; i < nums.size(); i++) {
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);

            swap(nums[idx], nums[i]);
            search(nums, idx + 1, ans);
            swap(nums[idx], nums[i]);
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,2};
    Solution solution;
    auto result = solution.permuteUnique(nums);
    for (const auto &permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
