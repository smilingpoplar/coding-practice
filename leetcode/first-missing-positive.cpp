//
//  first-missing-positive
//  https://leetcode.com/problems/first-missing-positive/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 期望变成数组[1..n]。位置i应放数i+1，即nums[i]==i+1；
        // 数x应在位置x-1，即nums[i]应在位置nums[i]-1，nums[nums[i]-1]==nums[i]。
        // 旋转置换：若nums[nums[i]-1]!=nums[i]，交换位置nums[i]-1和位置i处的值。
        const int N = nums.size();
        for (int i = 0; i < N; i++) {
            while (1 <= nums[i] && nums[i] <= N && nums[nums[i]-1] != nums[i]) {
                swap(nums[nums[i]-1], nums[i]);
            }
        }
        // first missing
        for (int i = 0; i < N; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return N + 1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1};
    
    Solution solution;
    cout << solution.firstMissingPositive(nums);
    
    return 0;
}
