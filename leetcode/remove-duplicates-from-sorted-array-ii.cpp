//
//  remove-duplicates-from-sorted-array-ii
//  https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
//
//  Created by smilingpoplar on 15/6/4.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 2) return N;
        int out = 2;
        for (int in = 2; in < N; in++) {
            if (nums[in] != nums[out-2]) {
                nums[out++] = nums[in];
            }
        }
        return out;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,1,2,2,3};
    Solution solution;
    cout << solution.removeDuplicates(nums);
    
    return 0;
}