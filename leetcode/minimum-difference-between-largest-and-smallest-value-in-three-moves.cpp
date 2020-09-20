//
//  minimum-difference-between-largest-and-smallest-value-in-three-moves
//  https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 4) return 0;
        sort(nums.begin(), nums.end());
        // 修改三个数，可以修改：
        // 3maxs、2maxs1min、1max, 2mins、3mins
        return min({nums[N-4] - nums[0], nums[N-3] - nums[1], nums[N-2] - nums[2], nums[N-1] - nums[3]});
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
