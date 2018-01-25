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
        vector<vector<int>> result;
        vector<int> combination;
        dfs(0, candidates, target, combination, result);
        return result;
    }
private:
    void dfs(int start, const vector<int> candiatates, int target,
             vector<int> &combination, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        if (target < 0) return;
        for (int i = start; i < candiatates.size(); i++) {
            // 遇到相同数字时，只对数字的第一次出现作递归
            if (i > start && candiatates[i] == candiatates[i - 1]) continue;
            combination.push_back(candiatates[i]);
            dfs(i + 1, candiatates, target - candiatates[i], combination, result);
            combination.pop_back();
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
