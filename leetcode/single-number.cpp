//
//  single-number.cpp
//  https://leetcode.com/problems/single-number/
//
//  Created by smilingpoplar on 15/4/30.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {3, 3, 4, 5, 5};
    Solution solution;
    cout << solution.singleNumber(nums);
    
    return 0;
}
