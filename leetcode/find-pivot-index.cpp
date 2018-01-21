//
//  find-pivot-index
//  https://leetcode.com/problems/find-pivot-index/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int N = nums.size();
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        int leftSum = 0;
        for (int i = 0; i < N; ++i) {
            if (leftSum == sum - nums[i] - leftSum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
