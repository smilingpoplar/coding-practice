//
//  longest-continuous-increasing-subsequence
//  https://leetcode.com/problems/longest-continuous-increasing-subsequence/
//
//  Created by smilingpoplar on 18/01/18.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int length = 0;
        for (int i = 0, start = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i-1] >= nums[i]) {
                start = i;
            }
            length = max(length, i - start + 1);
        }
        return length;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
