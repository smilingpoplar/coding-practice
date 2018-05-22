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
        // 猜这个“子数组和的最大值”mid，mid越大、子数组可越长、m越小
        // mid取值范围是[max(nums), sum(nums)]
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
    
    // 要构造返回[false, ..., false, true, ..., true]条件式，再用二分搜索找第一个true。
    // mid太小将分成>m个子数组，这时valid(mid)返回false；mid刚好时将分成=m个子数组，valid(mid)返回true
    // mid太大时将分成<m个数组，valid(mid)继续返回true。所以valid(x)表示分成的<=m个子数组。
    // 在valid(x)中要统计子数组数count。
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
