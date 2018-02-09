//
//  find-peak-element
//  https://leetcode.com/problems/find-peak-element/
//
//  Created by smilingpoplar on 15/5/27.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 顺序找到比下一元素大的nums[i]
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) return 2;
        }
        return nums.size() - 1;
    }
};
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 该题的peak元素肯定存在，用二分搜索排除范围
        int l = 0, u = nums.size() - 1;
        while (l < u) { // 最后剩一个元素时结束
            int mid = l + (u - l) / 2;
            if (nums[mid] < nums[mid+1]) {
                l = mid + 1;
            } else {
                u = mid;
            }
        }
        return l;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 3, 1};
    Solution solution;
    cout << solution.findPeakElement(nums);
    
    return 0;
}
