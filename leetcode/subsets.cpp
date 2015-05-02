//
//  subsets.cpp
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
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        subsets(0, nums, subset, result);
        return result;
    }
private:
    void subsets(size_t start, const vector<int> &nums, vector<int> &subset, vector<vector<int>> &result) {
        const size_t N = nums.size();
        if (start == N) {
            result.push_back(subset);
            return;
        }
        // 不选
        subsets(start + 1, nums, subset, result);
        // 选
        subset.push_back(nums[start]);
        subsets(start + 1, nums, subset, result);
        subset.pop_back();
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
