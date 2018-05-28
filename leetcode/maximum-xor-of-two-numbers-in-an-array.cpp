//
//  maximum-xor-of-two-numbers-in-an-array
//  https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // 假设maxXor=A^B，如果只考虑前缀i位，同样有prefixMaxXor=prefixA^prefixB。
        // 就像两数和的问题中，问是否存在两数a+b=sum，就是遍历数a看sum-a在数中是否存在。这里要问maxXor的第i位是否为1，
        // 假设guess=第i位为1的prefixMaxXor，就是问是否存在两数prefixA^prefixB=guess，
        // 就是遍历prefix看prefix^guess在前缀中是否存在。若存在，说明maxXor的第i位为1。
        int mask = 0, maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            unordered_set<int> st;
            mask |= (1 << i);
            for (int num : nums) {
                st.insert(num & mask);
            }

            int guess = maxXor | (1 << i); // 先猜maxXor的第i位为1，再看可不可行
            for (int prefix : st) {
                if (st.count(prefix ^ guess)) { // 可行
                    maxXor = guess;
                    break;
                }
            }
        }
        return maxXor;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
