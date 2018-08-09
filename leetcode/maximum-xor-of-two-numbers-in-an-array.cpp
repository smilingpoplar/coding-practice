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
        // 假设A^B=maxXor，只考虑前缀i位，同样有prefixA^prefixB=prefixMaxXor。
        // 就像两数之和的问题，问是否存在两数a+b=sum，就是对每个a看对应的sum-a是否在数集中。
        // 这里为使xor尽量大，问是否存在两个i位的前缀，使xor结果的第i位为1。
        // 同样，对每个i位的前缀a，看对应的maxXor^a是否在前缀集中。
        int mask = 0, maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            unordered_set<int> st;
            mask |= (1 << i);
            for (int num : nums) {
                st.insert(num & mask);
            }

            // 看是否存在两个前缀，使xor结果的第i位为1
            int guess = maxXor | (1 << i);
            for (int prefix : st) {
                if (st.count(guess ^ prefix)) { // 存在
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
