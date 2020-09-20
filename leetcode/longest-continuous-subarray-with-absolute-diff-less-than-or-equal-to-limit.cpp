//
//  longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
//  https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // 子段max(A)-min(A)<=limit
        // 同时保留滑动窗口的最大最小值
        const int N = nums.size();
        multiset<int> win;
        int ans = 0, lo = 0;
        for (int hi = 0; hi < N; hi++) {
            win.insert(nums[hi]);
            while (*win.rbegin() - *win.begin() > limit) {
                win.erase(win.find(nums[lo++]));
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
