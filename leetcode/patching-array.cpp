//
//  patching-array
//  https://leetcode.com/problems/patching-array/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // 设missing表示当前缺失的最小数，[1,missing)的数已都能相加得到
        long missing = 1;
        int i = 0;
        int count = 0;
        while (missing <= n) {
            if (i < nums.size() && nums[i] <= missing) {
                missing += nums[i++];
            } else {
                missing += missing;
                count++;
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
