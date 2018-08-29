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
        // 找波峰用栈，只找第一个波峰甚至没用到栈
        // 对应找下个更小的数
        const int N = nums.size();
        for (int i = 0; i < N - 1; i++) {
            if (nums[i] > nums[i+1]) return i;
        }
        return N - 1;
    }
};
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 找波峰，对应下一个更小的数
        // 变成找nums[i]>nums[i+1]的位置i
        const int N = nums.size();
        int l = 0, u = N - 1;
        while (l < u) { // 至少两个元素
            int mid = l + (u - l) / 2;
            if (nums[mid] > nums[mid+1]) {
                u = mid;
            } else {
                l = mid + 1;
            }
        }
        return u;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 3, 1};
    Solution solution;
    cout << solution.findPeakElement(nums);
    
    return 0;
}
