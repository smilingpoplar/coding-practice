//
//  non-decreasing-array
//  https://leetcode.com/problems/non-decreasing-array/
//
//  Created by smilingpoplar on 18/01/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int modified = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) {
                if (modified++) return false;
                if (i-2 < 0 || nums[i-2] <= nums[i]) {
                    nums[i-1] = nums[i];
                } else {
                    nums[i] = nums[i-1];
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
