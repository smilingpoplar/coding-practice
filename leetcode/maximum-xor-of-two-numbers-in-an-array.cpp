//
//  maximum-xor-of-two-numbers-in-an-array
//  https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // 为xor尽量大，尽量使xor高位为1。
        // 设guess=第i位为1的maxXor，看是否存在两个i位前缀a、b，使a^b==guess。
        // 类似两数之和的问题，看是否存在两数a+b=sum，对每个a看对应的sum-a在数集中是否存在
        int mask = 0, maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            unordered_set<int> st;
            mask |= (1 << i);
            for (int num : nums) {
                st.insert(num & mask);
            }

            // 尝试将第i位设为1
            int guess = maxXor | (1 << i);
            for (int a : st) {
                if (st.count(guess ^ a)) {
                    maxXor = guess;
                    break;
                }
            }
        }
        return maxXor;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
