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
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            // 考查整组数的第i位
            int ones = 0;
            for (int num : nums) {
                if ((num >> i) & 1) ones++;
            }
            ans += ones * (nums.size() - ones);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
