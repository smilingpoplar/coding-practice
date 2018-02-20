//
//  rotate-array
//  https://leetcode.com/problems/rotate-array/
//
//  Created by smilingpoplar on 15/5/21.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 先部分反转，再整体反转
        const int N = nums.size();
        k %= N;
        if (k == 0) return;
        reverse(nums, 0, N - k - 1);
        reverse(nums, N - k, N - 1);
        reverse(nums, 0, N - 1);
    }

    // 反转nums[start,end]
    void reverse(vector<int> &nums, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3,4,5,6,7};
    Solution solution;
    solution.rotate(nums, 3);
    for (auto num : nums) {
        cout << num << " ";
    }
    
    return 0;
}
