//
//  minimum-moves-to-equal-array-elements
//  https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
//
//  Created by smilingpoplar on 17/11/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // 走一步相当于把最大数减1，都减成最小数就都相等了
        int sum = 0, minNum = INT_MAX;
        for (int num : nums) {
            sum += num;
            if (num < minNum) minNum = num;
        }
        return sum - minNum * nums.size();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
