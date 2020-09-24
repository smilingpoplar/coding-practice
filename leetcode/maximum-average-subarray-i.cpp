//
//  maximum-average-subarray-i
//  https://leetcode.com/problems/maximum-average-subarray-i/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxSum = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i-k];
            maxSum = max(maxSum, sum);
        }
        return (double)maxSum / k;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
