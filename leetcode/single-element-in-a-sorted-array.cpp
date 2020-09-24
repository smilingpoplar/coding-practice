//
//  single-element-in-a-sorted-array
//  https://leetcode.com/problems/single-element-in-a-sorted-array/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 由题知N是奇数，对于[0..N-2]的一对对，找第一对nums[m]!=nums[m^1]
        // nums[m]!=nums[m^1]作二分搜索条件满足[0 ... 0 1 1 ...]形式
        int l = -1, u = (int)nums.size() - 1;
        while (l + 1 < u) {
            int mid = l + (u - l) / 2;
            if (nums[mid] != nums[mid ^ 1]) u = mid;
            else l = mid;
        }
        return nums[u];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
