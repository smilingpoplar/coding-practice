//
//  combination-sum
//  https://leetcode.com/problems/combination-sum/
//
//  Created by smilingpoplar on 15/5/26.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
        for (int i = start; i < candiatates.size(); ++i) {
            combination.push_back(candiatates[i]);
            dfs(i, candiatates, target - candiatates[i], combination, result);
            combination.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,3,6,7};
    Solution solution;
    auto result = solution.combinationSum(nums, 7);
    for (const auto &combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
