//
//  kth-largest-element-in-an-array
//  https://leetcode.com/problems/kth-largest-element-in-an-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, u = (int)nums.size() - 1;
        k--; // k是1-based，变成下标作比较
        while (l <= u) {
            int p = partition(nums, l, u);
            if (k == p) break;
            if (k < p) u = p - 1;
            else l = p + 1;
        }
        return nums[k];
    }

    int partition(vector<int> &nums, int l, int u) {
        if (l >= u) return l;
        // 单向划分
        // |t| >t | <=t |  ?  |
        //  l    m       i   u
        int m = l;
        for (int i = l + 1; i <= u; i++) {
            if (nums[i] > nums[l]) swap(nums[i], nums[++m]);
        }
        swap(nums[m], nums[l]);
        return m;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,1,5,4,3,6};
    Solution solution;
    cout << solution.findKthLargest(nums, 1);
    
    return 0;
}
