//
//  merge-sorted-array
//  https://leetcode.com/problems/merge-sorted-array/
//
//  Created by smilingpoplar on 15/5/23.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 从后往前合并
        int i1 = m - 1;
        int i2 = n - 1;
        int i = m + n - 1;
        while (i1 >= 0 && i2 >= 0) {
            nums1[i--] = nums1[i1] >= nums2[i2] ? nums1[i1--] : nums2[i2--];
        }
        while (i2 >= 0) {
            nums1[i--] = nums2[i2--];
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3, 5, 7};
    int m = (int)nums1.size();
    vector<int> nums2 = {2, 4, 5, 6};
    int n = (int)nums2.size();
    nums1.resize(m + n);
    
    Solution solution;
    solution.merge(nums1, m, nums2, n);
    for (auto num : nums1) {
        cout << num << " ";
    }
    
    return 0;
}
