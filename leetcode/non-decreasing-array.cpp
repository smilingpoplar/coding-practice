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
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] > nums[i+1]) {
                if (modified++) return false;
                if (i-1 < 0 || nums[i-1] <= nums[i+1]) {
                    nums[i] = nums[i+1];
                } else {
                    nums[i+1] = nums[i];
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
