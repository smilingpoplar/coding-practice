//
//  increasing-subsequences
//  https://leetcode.com/problems/increasing-subsequences/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> seq;
        search(nums, 0, seq, ans);
        return ans;
    }
    
    void search(vector<int>& nums, int idx, vector<int> &seq, vector<vector<int>> &ans) {
        if (seq.size() >= 2) ans.push_back(seq);

        // 有重复元素，相同元素只选第一个；不能排序数组
        unordered_set<int> selected;
        for (int i = idx; i < nums.size(); i++) {
            if (selected.count(nums[i])) continue;
            selected.insert(nums[i]);

            if (!seq.empty() && nums[i] < seq.back()) continue; // 确保递增
            seq.push_back(nums[i]);
            search(nums, i + 1, seq, ans);
            seq.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
