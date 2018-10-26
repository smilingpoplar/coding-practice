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
        // 从左到右扫描，若开始设置第三小，说明前面已有min1和min2
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
