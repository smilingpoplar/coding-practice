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
        const int N = (int)nums.size();
        return reversePairs(nums, 0, N - 1);
    }
    
    int reversePairs(vector<int>& nums, int l, int h) {
        if (l >= h) return 0;
        int mid = l + (h - l) / 2;
        int ans = reversePairs(nums, l, mid) + reversePairs(nums, mid + 1, h);
        
        // 统计组间逆序数，两指针同向遍历，不妨从数组末开始遍历
        int i = mid, j = h;
        while (i >= l) {
            while (j > mid && nums[i] <= (long)2 * nums[j])
                --j;
            // 现在j指向第一个满足的位置
            ans += j - mid;
            --i;
        }
        
        // 归并已排序的 nums[l, mid] 和 nums[mid + 1, h]
        vector<int> merged(h - l + 1);
        i = l, j = mid + 1;
        int k = 0;
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
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
