//
//  remove-duplicates-from-sorted-array
//  https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//
//  Created by smilingpoplar on 15/6/4.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 1;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] != nums[j - 1]) {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,2};
    Solution solution;
    cout << solution.removeDuplicates(nums);
    
    return 0;
}