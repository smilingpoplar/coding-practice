//
//  product-of-array-except-self
//  https://leetcode.com/problems/product-of-array-except-self/
//
//  Created by smilingpoplar on 15/8/1.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = (int)nums.size();
        auto result = vector<int>(N, 1);
        // 从左到右扫一遍
        for (int i = 0, left = 1; i < N; i++) {
            result[i] *= left;
            left *= nums[i];
        }
        // 从右到左扫一遍
        for (int i = N - 1, right = 1; i >= 0; i--) {
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 3, 4};
    Solution solution;
    auto result = solution.productExceptSelf(nums);
    for (int n : result) {
        cout << n << " ";
    }
    
    return 0;
}
