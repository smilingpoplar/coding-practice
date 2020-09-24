//
//  remove-element
//  https://leetcode.com/problems/remove-element/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int out = 0;
        for (int in = 0; in < nums.size(); in++) {
            if (nums[in] != val) {
                nums[out++] = nums[in];
            }
        }
        return out;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,2};
    Solution solution;
    cout << solution.removeElement(nums, 2);
    
    return 0;
}
