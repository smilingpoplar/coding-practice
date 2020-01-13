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
        // 两数的hamming距离指两数二进制的不同比特数。
        // 可以总体考虑一组数的某一位，该位有ones个1、(N-ones)个零，
        // 那么这组数在该位上的hamming距离是ones*(N-ones)。累加所有位。
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            // 考查整组数的第i位
            int ones = 0;
            for (int num : nums) {
                if (num & (1 << i)) ones++;
            }
            ans += ones * (nums.size() - ones);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
