//
//  total-hamming-distance
//  https://leetcode.com/problems/total-hamming-distance/
//
//  Created by smilingpoplar on 17/11/26.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        const int numBits = sizeof(int) * 8;
        for (int i = 0; i < numBits; i++) {
            // 考查整组数的第i位
            int ones = 0;
            for (int num : nums) {
                if ((num >> i) & 1) ones++;
            }
            total += ones * (nums.size() - ones);
        }
        return total;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
