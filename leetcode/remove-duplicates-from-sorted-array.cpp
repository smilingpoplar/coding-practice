//
//  remove-duplicates-from-sorted-array
//  https://leetcode.com/problems/remove-duplicates-from-sorted-array/
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
        if (N <= 1) return N;
        int write = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[write - 1]) {
                nums[write++] = nums[i];
            }
        }
        return write;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,2};
    Solution solution;
    cout << solution.removeDuplicates(nums);
    
    return 0;
}