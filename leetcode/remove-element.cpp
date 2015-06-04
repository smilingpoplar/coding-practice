//
//  remove-element
//  https://leetcode.com/problems/remove-element/
//
//  Created by smilingpoplar on 15/6/4.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = (int)nums.size();
        for (int i = 0; i < n;) {
            if (nums[i] == val) {
                --n;
                nums[i] = nums[n];
            } else {
                ++i;
            }
        }
        return n;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,2};
    Solution solution;
    cout << solution.removeElement(nums, 2);
    
    return 0;
}