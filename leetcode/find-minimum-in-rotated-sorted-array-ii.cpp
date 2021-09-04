//
//  find-minimum-in-rotated-sorted-array-ii
//  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // 旋转数组对半分，一半旋转一半有序，最小值在旋转那一半
        const int N = nums.size();
        int lo = 0, hi = N - 1;
        while (lo < hi) { // len([lo..hi])>=2
            int mi = lo + (hi - lo) / 2;
            // 由于mi向下取整，可能mi==lo，
            // 若用if (nums[lo] < nums[mi])，当mi==lo时这个if将被绕过
            // 用mi和hi就没这个问题，mi!=hi
            if (nums[mi] > nums[hi]) { // 右半旋转，且m位置不是min
                lo = mi + 1;
            } else if (nums[lo] > nums[mi]) { // 左半旋转
                hi = mi;
            } else { // nums[lo] <= nums[mi]<= nums[hi]
                hi--;
            }
        }
        return nums[lo];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {3,3,1,3};
    Solution solution;
    cout << solution.findMin(nums);
    
    return 0;
}
