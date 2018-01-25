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
        // 搜索树分叉，第0层从nums[0,N-1]中选一个（重复的数只选一次）放到nums[0]，
        // 第1层从剩下的nums[1,N-1]中选一个（重复的数只选一次）放到nums[1]，依次类推，
        // 第level层从剩下的nums[level,N-1]中选一个（重复的数只选一次）放到nums[level]，0<=level<N
        vector<vector<int>> result;
        dfs(0, nums, result);
        return result;
    }
private:
    void dfs(int level, vector<int> nums, vector<vector<int>> &result) {
        if (level == nums.size()) {
            result.push_back(nums);
            return;
        }
        unordered_set<int> selected;
        for (int i = level; i < nums.size(); i++) {
            if (selected.find(nums[i]) != selected.end()) continue;
            selected.insert(nums[i]);
            swap(nums[level], nums[i]);
            dfs(level + 1, nums, result);
            swap(nums[level], nums[i]);
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
