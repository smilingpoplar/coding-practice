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
        const int N = (int)nums.size();
        if (N <= 2) return N;
        int index = 2;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[index - 2]) {
                nums[index] = nums[i];
                ++index;
            }
        }
        return index;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,1,2,2,3};
    Solution solution;
    cout << solution.removeDuplicates(nums);
    
    return 0;
}