//
//  kth-largest-element-in-an-array
//  https://leetcode.com/problems/kth-largest-element-in-an-array/
//
//  Created by smilingpoplar on 15/6/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, (int)nums.size() - 1, k);
    }
private:
    // 在nums[l,r]中选第k大的数
    int findKthLargest(vector<int> &nums, int l, int r, int k) {
        if (l > r) return INT_MIN;
        // 不变式：
        // |t| > t |  ?  | <= t |
        // [l      [i   j]     r]
        int i = l + 1;
        int j = r;
        while (i <= j) {
            if (nums[i] > nums[l]) {
                ++i;
            } else {
                swap(nums[i], nums[j]); // 往右抛
                --j;
            }
        }
        swap(nums[j], nums[l]);
        
        int order = j - l + 1; //nums[j]是第几大的数
        if (k == order) return nums[j];
        if (k < order) return findKthLargest(nums, l, j - 1, k);
        return findKthLargest(nums, j + 1, r, k - order);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,1,5,4,3,6};
    Solution solution;
    cout << solution.findKthLargest(nums, 1);
    
    return 0;
}
