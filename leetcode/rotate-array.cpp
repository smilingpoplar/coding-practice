//
//  rotate-array
//  https://leetcode.com/problems/rotate-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
        reverse(nums, 0, N - 1 - k);
        reverse(nums, N - k, N - 1);
        reverse(nums, 0, N - 1);
    }

    void reverse(vector<int> &nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
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
