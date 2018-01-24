//
//  maximum-product-of-three-numbers
//  https://leetcode.com/problems/maximum-product-of-three-numbers/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        const int N = nums.size();
        if (N < 3) return 0;
        sort(nums.begin(), nums.end());
        int ans = nums[N-1] * nums[N-2] * nums[N-3];
        if (nums[1] < 0) {
            ans = max(ans, nums[0] * nums[1] * nums[N-1]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
