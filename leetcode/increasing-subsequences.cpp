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
        set<vector<int>> ans;
        vector<int> seq;
        search(nums, 0, seq, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
    void search(vector<int>& nums, int idx, vector<int> &seq, set<vector<int>> &ans) {
        if (seq.size() >= 2) ans.insert(seq);

        for (int i = idx; i < nums.size(); i++) {
            if (!seq.empty() && nums[i] < seq.back()) continue;
            seq.push_back(nums[i]);
            search(nums, i + 1, seq, ans);
            seq.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
