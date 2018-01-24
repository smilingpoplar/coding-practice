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
        // 每一步相当于把最大数减1，什么时候都减成最小数就都相等了
        int sum = 0;
        int min = INT_MAX;
        for (int num : nums) {
            sum += num;
            if (num < min) min = num;
        }
        return sum - min * nums.size();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
