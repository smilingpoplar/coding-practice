//
//  set-mismatch
//  https://leetcode.com/problems/set-mismatch/
//
//  Created by smilingpoplar on 17/12/11.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();
        int x = 0;
        for (int num : nums) x ^= num;
        for (int i = 1; i <= N; i++) x ^= i;
        // x = duplicate^missing
        int lastBit = x & -x;
        int xor0 = 0, xor1 = 0;
        for (int num : nums) {
            if (num & lastBit) xor1 ^= num;
            else xor0 ^= num;
        }
        for (int i = 1; i <= N; i++) {
            if (i & lastBit) xor1 ^= i;
            else xor0 ^= i;            
        } 
        // xor0和xor1 是 duplicate和missing，不知哪个是哪个
        for (int num : nums) {
            if (num == xor0) {
                return { xor0, xor1 };
            }
        }
        return { xor1, xor0 };
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
