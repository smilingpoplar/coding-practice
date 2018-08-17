//
//  first-missing-positive
//  https://leetcode.com/problems/first-missing-positive/
//
//  Created by smilingpoplar on 15/5/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 旋转置换
        // 把位置i的[1..n]内的数和位置j=nums[i]-1的数交换，
        // nums[i]-1是因为正数是1-based
        const int N = nums.size();
        for (int i = 0; i < N; i++) {
            for (int j = nums[i] - 1; 
                 1 <= nums[i] && nums[i] <= N && nums[i] != nums[j];
                 j = nums[i] - 1) {
                swap(nums[i], nums[j]);
            }
        }
        // first missing
        for (int i = 0; i < N; i++) {
            if (i != nums[i] - 1) return i + 1;
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
