//
//  single-element-in-a-sorted-array
//  https://leetcode.com/problems/single-element-in-a-sorted-array/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 每两个数配对，找第一个不配对的数，即找第一个 nums[mid]!=nums[mid^1] 的数
        int l = 0, u = nums.size() - 1;
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (nums[mid] != nums[mid ^ 1]) u = mid - 1;
            else l = mid + 1;
        }
        return nums[l];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
