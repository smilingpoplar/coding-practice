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
        // 猜“子段和的最大值”x，x取值范围是[max(nums), sum(nums)]
        int mx = INT_MIN;
        int sum = 0;
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
    
    // 考虑子段和的最大值x和子段数有什么关系。x越小、子段越短、子段数越多；x越大、子段越长、子段数越少。
    // 二分搜索要在[0 0 ... 0 1 1 ...]中找第一个1，因此设valid(x)表示子段数<=m。
    // 在valid(x)中统计子段和<=x的子段数。
    bool valid(int mid, vector<int> &nums, int m) {
        int count = 1;
        int total = 0;
        for (int num : nums) {
            total += num;
            if (total > mid) {
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
