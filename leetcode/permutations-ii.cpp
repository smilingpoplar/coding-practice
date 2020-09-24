//
//  permutations-ii
//  https://leetcode.com/problems/permutations-ii/
//
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
        const int N = nums.size();
        if (idx == N) {
            ans.push_back(nums);
            return;
        }
        
        // 有swap()扰乱排序，排序并判断相邻元素不能去重
        unordered_set<int> seen;
        for (int i = idx; i < N; i++) {
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
