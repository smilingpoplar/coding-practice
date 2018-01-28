//
//  move-zeroes
//  https://leetcode.com/problems/move-zeroes/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[write++] = nums[i];
            }
        }
        while (write < nums.size()) {
            nums[write++] = 0;
        }
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
