//
//  reverse-pairs
//  https://leetcode.com/problems/reverse-pairs/
//
//  Created by smilingpoplar on 17/11/27.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
    int mergeSort(vector<int>& nums, int l, int h) {
        if (l >= h) return 0;
        int mid = l + (h - l) / 2;
        int ans = mergeSort(nums, l, mid) + mergeSort(nums, mid + 1, h);
        
        // 统计组间逆序数，两指针同向遍历，不妨从数组末开始遍历
        for (int i = mid, j = h; i >= l; i--) {
            while (j > mid && nums[i] <= (long)2 * nums[j]) j--;
            ans += j - mid; // 现在j指向第一个满足的位置
        }
        merge(nums, l, mid, h);            
        return ans;
    }
    
    // 归并已排序的 nums[l, mid] 和 nums[mid + 1, h]
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
        while (i <= mid) {
            merged[k++] = nums[i++];               
        }
        while (j <= h) {
            merged[k++] = nums[j++];            
        }
        for (int k = 0; k < merged.size(); k++) {
            nums[l + k] = merged[k];
        }
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
