//
//  wiggle-sort-ii
//  https://leetcode.com/problems/wiggle-sort-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int N = nums.size();
        // 按逆序处理，下面先找media、再按>median三路划分
        // 可自己实现findKthLargest，其中k是1-based，中位数k=(N+1)/2
        // int median = findKthLargest(nums, (N + 1) / 2);
        // 见 https://leetcode.com/problems/kth-largest-element-in-an-array/
        // 这里也可以调用nth_element(..., greater<int>())，其中midptr是0-based
        auto midptr = nums.begin() + (N - 1) / 2; // 0-based偏移中位数(N+1)/2-1
        nth_element(nums.begin(), midptr, nums.end(), greater<int>());
        int median = *midptr;
        
        // 把后一半坐标[N/2..]放到偶位、前一半坐标[0..N/2)放到奇位的下标映射：i => (2*i+1) % (N|1)
        // 见 https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)+O(1)-after-median-Virtual-Indexing
        auto idx = [&](int i) { return (2*i+1) % (N|1); };
        // 三路划分：| >median | =median |  ?  | <median |
        //          0         i         j    k        N-1
        // i指向>median待写入位置，j指向待处理位置，k指向<median待写入位置
        int i = 0, j = 0, k = N - 1;
        while (j <= k) {
            if (nums[idx(j)] > median) {
                swap(nums[idx(j)], nums[idx(i)]);
                i++, j++;
            } else if (nums[idx(j)] < median) {
                swap(nums[idx(j)], nums[idx(k)]);
                k--;
            } else {
                j++;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
