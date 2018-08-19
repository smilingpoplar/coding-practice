//
//  two-sum-ii-input-array-is-sorted
//  https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] == target) {
                return { l + 1, r + 1 };
            } else if (nums[l] + nums[r] < target) {
                l++;
            } else {
                r--;
            }
        }
        return { -1, -1 };
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
