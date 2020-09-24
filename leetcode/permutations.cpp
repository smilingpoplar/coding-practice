//
//  permutations
//  https://leetcode.com/problems/permutations/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        search(nums, 0, ans);
        return ans;
    }
private:
    void search(vector<int> nums, int idx, vector<vector<int>> &ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            search(nums, idx + 1, ans);
            swap(nums[idx], nums[i]);
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3};
    Solution solution;
    auto result = solution.permute(nums);
    for (const auto &permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
