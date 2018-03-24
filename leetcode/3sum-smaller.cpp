//
//  3sum-smaller
//  https://leetcode.com/problems/3sum-smaller/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // 只问有多少个满足条件的三元组，没问这些三元组的下标，数组可以排序
        sort(nums.begin(), nums.end());
        
        const int N = nums.size();
        int ans = 0;
        for (int i = 0; i < N - 2; i++) {
            // 两端指针法
            int j = i + 1, k = N - 1;
            while (j < k) {
                if (nums[j] + nums[k] < target - nums[i]) {
                    // j&k, j&(k-1), j&(k-2) ... j&(j+1) 的数对都满足
                    ans += k - j;
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
