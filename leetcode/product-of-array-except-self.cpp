//
//  product-of-array-except-self
//  https://leetcode.com/problems/product-of-array-except-self/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        vector<int> ans(N, 1);
        // 从左到右扫一遍
        for (int i = 0, lProd = 1; i < N; i++) {
            ans[i] *= lProd;
            lProd *= nums[i];
        }
        // 从右到左扫一遍
        for (int i = N - 1, rProd = 1; i >= 0; i--) {
            ans[i] *= rProd;
            rProd *= nums[i];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 3, 4};
    Solution solution;
    auto ans = solution.productExceptSelf(nums);
    for (int n : ans) {
        cout << n << " ";
    }
    
    return 0;
}
