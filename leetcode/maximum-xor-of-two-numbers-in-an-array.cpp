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
        // 假设A^B=maxXor，只考虑i位前缀，有prefixA^prefixB=prefixMaxXor。
        // 就像两数之和的问题，问是否存在两数a+b=sum，解法是对每个a看对应的sum-a在数集中是否存在。
        // 这里为使xor尽量大，特意设置guess=第i位为1的prefixMaxXor，再问是否存在两个i位前缀a^b==guess。
        // 解法是对每个i位前缀a，看对应的guess^a在前缀集中是否存在。存在则maxXor的第i位为1。
        int mask = 0, maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            unordered_set<int> st;
            mask |= (1 << i);
            for (int num : nums) {
                st.insert(num & mask);
            }

            // 是否存在两个i位前缀，使xor结果的第i位为1
            int guess = maxXor | (1 << i);
            for (int a : st) {
                if (st.count(guess ^ a)) { // 存在
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
