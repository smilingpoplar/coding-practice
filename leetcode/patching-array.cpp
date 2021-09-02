//
//  patching-array
//  https://leetcode.com/problems/patching-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // 设[1..missing)已能由数组数相加获得，尝试扩展上边界missing
        long missing = 1;
        int i = 0, ans = 0;
        while (missing <= n) { // 最终missing>n，[1..missing)包含[1..n]
            // nums[i]已能由相加获得（<missing）或在数组中（=missing）
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
