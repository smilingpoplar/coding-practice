//
//  increasing-triplet-subsequence
//  https://leetcode.com/problems/increasing-triplet-subsequence/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // 从左到右扫描，只要min2被设置了，说明它前面有比它小的min1
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int num : nums) {
            if (num <= min1) {
                min1 = num;
            } else if (num <= min2) {
                min2 = num;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
