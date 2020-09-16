//
//  single-number-ii
//  https://leetcode.com/problems/single-number-ii/
//
//  Created by smilingpoplar on 15/5/2.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 泛化成：其他数出现k次，某个数出现p次（p不能被k整除），找这单个数
        // bit运算各个位相互独立，下面用int同时统计相互独立的各个位，逻辑上把整个int当作一个bit
        // 要统计某位上出现1的次数，需要个mod k计数器（该计数器共m>=lgk位），设bm,..,b2,b1表示该计数器的位，
        // 1. 进位规则：..., b4^=b3&b2&b1&nums[i], b3^=b2&b1&nums[i], b2^=b1&nums[i], b1^=nums[i]
        //    即 从最高位开始更新，后面位和新数nums[i]都为1时才进位
        // 2. 计数为k时直接清零：当bm,..,b1的各个位分别等于k的各个位km,..,k1时，计数为k，故判断计数为k的表达式
        //    为(bm_km)&..&(b1_k1)。分量(bj_kj)表示于kj==1时取bj、kj==0时取~bj
        //    计数为k时直接清零的 mask = ~((b1_k1)&..&(bm_km))
        //    有了mask后清零：..., b4&=mask, b3&=mask, b2&=mask, b1&=mask
        // 3. 最终要找的是计数>0，即逻辑位(b1|b2|b3|b4|...)为1
        int b1 = 0, b2 = 0;
        int mask = 0;
        for (int num : nums) {
            b2 ^= b1 & num;
            b1 ^= num;
            mask = ~(b1 & b2); // k =3 =(11)_2
            b2 &= mask;
            b1 &= mask;
        }
        return b1 | b2;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {5, 5, 4, 5, 3, 3, 3};
    Solution solution;
    cout << solution.singleNumber(nums);
    
    return 0;
}
