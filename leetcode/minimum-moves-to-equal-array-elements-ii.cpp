//
//  minimum-moves-to-equal-array-elements-ii
//  https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
//
//  Created by smilingpoplar on 17/11/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        int count = 0;
        for (int i = 0, j = N - 1; i < j; i++, j--) {
            count += nums[j] - nums[i];
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
