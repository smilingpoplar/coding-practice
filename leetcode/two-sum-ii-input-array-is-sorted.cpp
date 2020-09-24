//
//  two-sum-ii-input-array-is-sorted
//  https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) {
                return { l + 1, r + 1 };
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
        return { -1, -1 };
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
