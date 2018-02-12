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
        // 假设存在两数A和B，maxXor=A^B，那么B=A^maxXor。如果只考虑前i位，同样有prefixMaxXor=prefixA^prefixB，
        // prefixB=prefixA^prefixMaxXor。现在把所有数的前i位prefix放进集合set，要检验maxXor的第i位是否为1。
        // 让candidate=第i位设为1的prefixMaxXor，对set中每个prefix，看prefixA^candidate==prefixB是否也在set中。
        // 如果prefixB也在，说明prefixMaxXor的第i位为1可行。
        int maxXor = 0, mask = 0;
        for (int i = 31; i >= 0; i--) {
            unordered_set<int> st;
            mask |= (1 << i);
            for (int num : nums) {
                st.insert(num & mask);
            }
            
            int candidate = maxXor | (1 << i);
            for (int prefix : st) {
                if (st.find(prefix ^ candidate) != st.end()) {
                    maxXor = candidate;
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
