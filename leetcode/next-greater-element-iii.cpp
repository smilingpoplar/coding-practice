//
//  next-greater-element-iii
//  https://leetcode.com/problems/next-greater-element-iii/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        // 1. 从右往左找第一个波峰前的数，即找第一个nums[i]<nums[i+1]的位置i
        // 2. 在i右边、从波峰往右是个递减序列，从右往左肯定能找到第一个nums[j]>nums[i]的位置j
        // 3. 交换nums[i]和nums[j]，交换后从波峰往右仍是个递减序列
        // 4. 反转这个递减序列
        string s = to_string(n);
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i+1]) i--;
        if (i < 0) return -1;
        int j = s.size() - 1;
        while (j > i && s[j] <= s[i]) j--;
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        long ans = stol(s); // 溢出判断
        return (ans <= INT_MAX) ? ans : -1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
