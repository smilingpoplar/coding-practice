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
        // 按逆序处理，所以下面找kthLargest、三路划分先找>median
        // (N+1)/2是中位数，因为取下整，偶数个时指向偏前
        int median = findKthLargest(nums, (N + 1) / 2);
        // 这里也可以调用nth_element()（第n个最小的数）找偏后的中位数
        // auto midptr = nums.begin() + N / 2;
        // nth_element(nums.begin(), midptr, nums.end());
        // int median = *midptr;
        
        // 把后一半坐标[N/2..]放到偶位、前一半坐标[0..N/2)放到奇位的下标映射：i => (2*i+1) % (N|1)
        // 见 https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)+O(1)-after-median-Virtual-Indexing
        auto idx = [&](int i) { return (2*i+1) % (N|1); };
        // 三路划分：| >median | =median |  ?  | <median |
        //          0         i         j    k        N-1
        // i指向>median待写入位置，j指向待处理位置，k指向<median待写入位置
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

    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, u = (int)nums.size() - 1;
        while (l <= u) {
            int p = partition(nums, l, u); // p跟下标k-1比较，因为第k大数的下标应该是k-1
            if (k - 1 == p) return nums[p];
            if (k - 1 < p) u = p - 1;
            else l = p + 1;
        }
    }

    int partition(vector<int> &nums, int l, int u) {
        if (l >= u) return l;
        // 单向划分：| >t | <=t |  ?  |
        //         l    m      i    u
        int m = l;
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
