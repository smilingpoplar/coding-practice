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
        // 最小两数、最大三数
        const int N = nums.size();
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int num : nums) {
            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
            
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }
        }
        
        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};

/*
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[N-1] * nums[N-2] * nums[N-3], nums[0] * nums[1] * nums[N-1]);
    }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
