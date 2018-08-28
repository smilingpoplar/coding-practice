//
//  shortest-unsorted-continuous-subarray
//  https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
//
//  Created by smilingpoplar on 17/12/01.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 若nums[i]在排序后该在的位置，有maxLeft[i]==nums[i]==minRight[i]。
        // 从左到右找nums[r]!=maxLeft[r]的最大r、得无序的最右边界；
        // 从右到左找nums[l]!=minRight[l]的最小l、得无序的最左边界。
        const int N = nums.size();
        int maxLeft = INT_MIN, minRight = INT_MAX;
        int l = 0, r = -1; // 如果nums[]有序
        for (int i = 0; i < N; i++) {
            maxLeft = max(maxLeft, nums[i]);
            if (nums[i] != maxLeft) r = i;
            
            int j = N - 1 - i;
            minRight = min(minRight, nums[j]);
            if (nums[j] != minRight) l = j;
        }
        return r - l + 1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
