//
//  search-in-rotated-sorted-array
//  https://leetcode.com/problems/search-in-rotated-sorted-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 旋转数组对半分后，一半是有序数组、一半是旋转数组
        int lo = 0, hi = (int)nums.size() - 1;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] == target) return mi;
            
            if (nums[lo] <= nums[mi]) { // 左半有序
                if (nums[lo] <= target && target < nums[mi]) {
                    hi = mi - 1;
                } else {
                    lo = mi + 1;
                }
            } else { // 右半有序
                if (nums[mi] < target && target <= nums[hi]) {
                    lo = mi + 1;
                } else {
                    hi = mi - 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution solution;
    cout << solution.search(nums, 1) << endl;
    cout << solution.search(nums, 3) << endl;
    
    return 0;
}
