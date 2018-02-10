//
//  wiggle-sort-ii
//  https://leetcode.com/problems/wiggle-sort-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int N = nums.size();
        int median = findKthLargest(nums, (N + 1) / 2, 0, N - 1);
        // 虚拟索引，见 https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)+O(1)-after-median-Virtual-Indexing
        // [0 1 2 3 4 5 ...] => [1 3 5 ...0 2 4 ...]，映射关系：i => (2*i+1) % (N|1)
        // 为什么是 % (N|1)，用例子推导得到，这映射关系只适用于降序划分
        auto idx = [&](int i) { 
            return (2*i+1) % (N|1);
        };
        // 三路划分：>median、==median、<median
        int i = 0, j = 0, k = nums.size() - 1;
        while (j <= k) {
            if (nums[idx(j)] > median) {
                swap(nums[idx(j)], nums[idx(i)]);
                i++;
                j++;
            } else if (nums[idx(j)] < median) {
                swap(nums[idx(j)], nums[idx(k)]);
                k--;
            } else {
                j++;
            }
        }
    }

    int findKthLargest(vector<int>& nums, int k, int l, int u) {
        int p = partition(nums, l, u);
        int order = p - l + 1; // nums[p]是第几大的数
        if (k == order) return nums[p];
        if (k < order) return findKthLargest(nums, k, l, p - 1);
        return findKthLargest(nums, k - order, p + 1, u);
    }

    // 单向划分：>t、<=t
    int partition(vector<int> &nums, int l, int u) {
        if (l >= u) return l;
        int i = l + 1, j = u; // i指向>t的待写入部分，j指向<=t的待写入部分
        while (i <= j) {
            if (nums[i] > nums[l]) {
                ++i;
            } else {
                swap(nums[i], nums[j]);
                --j;
            }
        }
        swap(nums[j], nums[l]);
        return j;
    }    
};

int main(int argc, const char * argv[]) {
    return 0;
}
