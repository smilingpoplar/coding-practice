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
        vector<string> result;
        int start = 0;
        while (start < nums.size()) {
            // 输出nums[start,end)范围
            int end = start + 1;
            while (end < nums.size() && nums[end] == nums[end - 1] + 1) ++end;
            
            string range = to_string(nums[start]);
            if (end > start + 1) {
                range += "->" + to_string(nums[end - 1]);
            }
            result.push_back(range);
            
            start = end;
        }
        return result;
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
