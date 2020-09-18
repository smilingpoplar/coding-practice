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
        int mx = 0;
        long sum = 0;
        for (int num : nums) {
            mx = max(mx, num);
            sum += num;
        }

        // 二分搜素猜子段和的最大值x
        long l = mx, u = sum;
        while (l <= u) {
            long mid = l + (u - l) / 2;
            if (enough(mid, nums, m)) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;        
    }
    
    bool enough(long x, vector<int> &nums, int m) {
        // 子段和的最大值x和子段数m的关系，是关于x的递减函数count(x)
        // 条件式count(x)<=m满足二分搜索的条件形式[0 0 ... 0 1 1 ...]
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
