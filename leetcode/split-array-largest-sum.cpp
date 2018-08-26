//
//  split-array-largest-sum
//  https://leetcode.com/problems/split-array-largest-sum/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // 各子段和的最大值x在值范围[max(nums), sum(nums)]
        // 考虑x和子段数m的关系：x越小、子段越短、子段数越多；x越大、子段越长、子段数越少
        // 二分搜索条件valid(x)表示子段数<=m，满足二分搜索要返回[0 0 ... 0 1 1 ...]的要求
        // 因此，valid(x)中要统计子段和<=x的个数count，判断是否count<=m
        int mx = INT_MIN, sum = 0;
        for (int num : nums) {
            mx = max(mx, num);
            sum += num;
        }
        int l = mx, u = sum;
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (valid(mid, nums, m)) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;        
    }
    
    bool valid(int x, vector<int> &nums, int m) {
        int count = 1;
        int total = 0;
        for (int num : nums) {
            total += num;
            if (total > x) {
                count++;
                total = num;
                if (count > m) return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
