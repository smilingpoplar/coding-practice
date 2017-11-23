//
//  wiggle-subsequence
//  https://leetcode.com/problems/wiggle-subsequence/
//
//  Created by smilingpoplar on 17/11/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                up = down + 1;
            } else if (nums[i] < nums[i-1]) {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
