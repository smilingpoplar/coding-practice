//
//  subsets
//  https://leetcode.com/problems/subsets/
//
//  Created by smilingpoplar on 15/5/2.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        search(nums, 0, subset, ans);
        return ans;
    }
private:
    void search(const vector<int> &nums, int idx, 
                vector<int> &subset, vector<vector<int>> &ans) {
        ans.push_back(subset);
        for (int i = idx; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            search(nums, i + 1, subset, ans);
            subset.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 3};
    Solution solution;
    auto subsets = solution.subsets(nums);
    for (const auto &subset: subsets) {
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
