//
//  reverse-pairs
//  https://leetcode.com/problems/reverse-pairs/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, (int)nums.size() - 1);
    }

    int mergeSort(vector<int>& nums, int l, int h) {
        if (l >= h) return 0;
        int mid = l + (h - l) / 2;
        int ans = mergeSort(nums, l, mid) + mergeSort(nums, mid + 1, h);

        // 统计组间逆序数
        for (int j = mid + 1; j <= h; j++) {
            // nums[l..mid]中找第一个>2*nums[j]的i
            auto it = upper_bound(begin(nums) + l, begin(nums) + mid + 1, 2l * nums[j]);
            int i = it - begin(nums);
            ans += mid - i + 1;  // 位置[i..mid]与i逆序
        }
        merge(nums, l, mid, h);
        return ans;
    }

    // 归并已排序的 nums[l..mid] 和 nums[mid+1..h]
    void merge(vector<int>& nums, int l, int mid, int h) {
        vector<int> merged(h - l + 1);
        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= h) {
            if (nums[i] < nums[j]) {
                merged[k++] = nums[i++];
            } else {
                merged[k++] = nums[j++];
            }
        }
        while (i <= mid) merged[k++] = nums[i++];
        while (j <= h) merged[k++] = nums[j++];
        for (int k = 0; k < merged.size(); k++) {
            nums[l + k] = merged[k];
        }
    }
};
