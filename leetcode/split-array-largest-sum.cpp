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
        // x和子段数的关系：x越小、子段越短、子段数越多；x越大、子段越长、子段数越少
        // 设二分搜索条件valid(x)表示“子段和<=x的子段数”count<=m，满足形式[0 0 ... 0 1 1 ...]
        int mx = 0;
        long sum = 0;
        for (int num : nums) {
            mx = max(mx, num);
            sum += num;
        }

        long l = mx, u = sum;
        while (l <= u) {
            long mid = l + (u - l) / 2;
            if (valid(mid, nums, m)) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;        
    }
    
    bool valid(long x, vector<int> &nums, int m) {
        int count = 1;
        long sum = 0;
        for (int num : nums) {
            sum += num;
            if (sum > x) {
                count++;
                sum = num;
                if (count > m) return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
