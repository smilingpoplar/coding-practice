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
        if (nums.empty()) return 0;
        const int N = nums.size();
        int sum = 0;
        int min = INT_MAX;
        for (int num : nums) {
            sum += num;
            if (num < min) min = num;
        }
        return sum - min * N;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
