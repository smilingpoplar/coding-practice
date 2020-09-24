//
//  longest-continuous-increasing-subsequence
//  https://leetcode.com/problems/longest-continuous-increasing-subsequence/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;
        for (int i = 0, start = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] <= nums[i-1]) start = i;
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
