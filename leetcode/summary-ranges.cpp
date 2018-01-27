//
//  summary-ranges
//  https://leetcode.com/problems/summary-ranges/
//
//  Created by smilingpoplar on 15/6/27.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1 || nums[i] != nums[i+1] - 1) {
                string range = to_string(nums[left]);
                if (i > left) range += "->" + to_string(nums[i]);
                ans.push_back(range);
                left = i + 1;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {0,1,2,4,5,7};
    Solution solution;
    auto result = solution.summaryRanges(nums);
    for (auto &range : result) {
        cout << range << " ";
    }
    
    return 0;
}
