//
//  combination-sum
//  https://leetcode.com/problems/combination-sum/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        search(candidates, 0, target, comb, ans);
        return ans;
    }

    void search(const vector<int> candiatates, int idx, int target,
                vector<int> &comb, vector<vector<int>> &ans) {
        if (target < 0) return;
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        
        for (int i = idx; i < candiatates.size(); i++) {
            comb.push_back(candiatates[i]);
            search(candiatates, i, target - candiatates[i], comb, ans);
            comb.pop_back();
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
