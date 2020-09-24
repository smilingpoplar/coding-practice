//
//  running-sum-of-1d-array
//  https://leetcode.com/problems/running-sum-of-1d-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        partial_sum(begin(nums), end(nums), begin(nums));
        return nums;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
