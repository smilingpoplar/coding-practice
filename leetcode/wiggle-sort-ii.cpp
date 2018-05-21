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
        int median = findKthLargest(nums, 0, N - 1, (N + 1) / 2);
        // 虚拟下标映射：i => (2*i+1) % (N|1)
        // 见 https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)+O(1)-after-median-Virtual-Indexing
        auto idx = [&](int i) { return (2*i+1) % (N|1); };
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

    int findKthLargest(vector<int>& nums, int l, int u, int k) {
        int p = partition(nums, l, u);
        int order = p - l + 1; // nums[p]是第几大的数
        if (k == order) return nums[p];
        if (k < order) return findKthLargest(nums, l, p - 1, k);
        return findKthLargest(nums, p + 1, u, k - order);
    }

    int partition(vector<int> &nums, int l, int u) {
        if (l >= u) return l;
        // 单向划分，将数组分为>t、<=t、?三段
        int m = l; // m指向第一段末尾、i指向第三段开头
        for (int i = l + 1; i <= u; i++) {
            if (nums[i] > nums[l]) {
                swap(nums[i], nums[++m]);
            }
        }
        swap(nums[m], nums[l]);
        return m;
    }   
};

int main(int argc, const char * argv[]) {
    return 0;
}
