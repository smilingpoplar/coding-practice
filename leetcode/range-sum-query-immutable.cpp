//
//  range-sum-query-immutable
//  https://leetcode.com/problems/range-sum-query-immutable/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class NumArray {
    vector<int> sum; // sum[i]表示nums[0..i-1]的和
public:
    NumArray(vector<int> nums) {
        sum = vector<int>(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main(int argc, const char * argv[]) {    
    return 0;
}
