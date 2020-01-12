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
        // 贪婪法，摇摆发生时增长子序列
        if (nums.empty()) return 0;
        int ans = 1;
        int prevDiff = 0;
        for (int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - nums[i-1];
            if ((diff > 0 && prevDiff <= 0) || (diff < 0 && prevDiff >= 0)) {
                ans++;
                prevDiff = diff;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
