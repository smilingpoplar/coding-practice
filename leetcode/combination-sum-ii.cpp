//
//  combination-sum-ii
//  https://leetcode.com/problems/combination-sum-ii/
//
//  Created by smilingpoplar on 15/5/26.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        search(candidates, target, 0, comb, ans);
        return ans;
    }

    void search(const vector<int> candiatates, int target, int idx,
             vector<int> &comb, vector<vector<int>> &ans) {
        if (target < 0) return;
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        
        for (int i = idx; i < candiatates.size(); i++) {
            // 有重复元素，相同元素只选第一个
            if (i > idx && candiatates[i] == candiatates[i-1]) continue;
            comb.push_back(candiatates[i]);
            search(candiatates, target - candiatates[i], i + 1, comb, ans);
            comb.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {10,1,2,7,6,1,5};
    Solution solution;
    auto result = solution.combinationSum2(nums, 8);
    for (const auto &combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
