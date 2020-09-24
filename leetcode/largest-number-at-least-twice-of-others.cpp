//
//  largest-number-at-least-twice-of-others
//  https://leetcode.com/problems/largest-number-at-least-twice-of-others/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        const int N = nums.size();
        if (N == 1) return 0;
        int max1 = INT_MIN, max2, idx;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
                idx = i;
            } else if (nums[i] > max2) {
                max2 = nums[i];
            }
        }
        return (max1 >= 2 * max2) ? idx : -1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
