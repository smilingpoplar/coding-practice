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
        // 设[1..missing)已能由数组数相加获得，尝试扩展上边界msssing
        long missing = 1;
        int i = 0, ans = 0;
        while (missing <= n) {
            // nums[i]已能由相加获得（<missing）或在数组中（==missing）
            if (i < nums.size() && nums[i] <= missing) {
                missing += nums[i];
                i++;
            } else {
                missing += missing; // 补上数missing
                ans++;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
