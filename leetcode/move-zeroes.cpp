//
//  move-zeroes
//  https://leetcode.com/problems/move-zeroes/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int N = nums.size();
        int out = 0;
        for (int in = 0; in < N; in++) {
            if (nums[in] != 0) {
                nums[out++] = nums[in];
            }
        }
        while (out < N) {
            nums[out++] = 0;
        }
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
