//
//  remove-duplicates-from-sorted-array
//  https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int out = 1; // 第一个数肯定不删除
        for (int in = 1; in < nums.size(); in++) {
            if (nums[in] != nums[out-1]) {
                nums[out++] = nums[in];
            }
        }
        return out;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,2};
    Solution solution;
    cout << solution.removeDuplicates(nums);
    
    return 0;
}
