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
        // bit运算各个位相互独立，下面用int同时统计相互独立的各个位，逻辑上可把整个int当作一个bit
        // 要统计某位上出现1的次数，需要个mod k计数器（该计数器共m>=lgk位），设xm,..,x2,x1表示该计数器的位，
        // 1. 进位规则：..., x4^=x3&x2&x1&nums[i], x3^=x2&x1&nums[i], x2^=x1&nums[i], x1^=nums[i]
        //    即 后面位和新数nums[i] 都为1时才进位到当前位
        // 2. 计数为k时直接清零：当xm,..,x1的各个位分别等于k的各个位km,..,k1时，计数为k；判断计数为k的表达式为
        //    (xm==km)&..&(x1==k1)，分量yj:(xj==kj)等价于kj==1时取xj、kj==0时取xj'(xj'表示xj取非)，
        //    因此，判断计数为k的表达式为y1&..&ym；
        //    计数为k时直接清零的 mask = ~(y1&..&ym)
        //    有了mask后清零：..., x4&=mask, x3&=mask, x2&=mask, x1&=mask
        // 3. 最终只要计数器的计数>0，即x1|x2|x3|x4|...，该统计位为1
        int x1 = 0, x2 = 0;
        int mask = 0;
        for (int num : nums) {
            x2 ^= x1 & num;
            x1 ^= num;
            mask = ~(x1 & x2); // k =3 =(11)_2
            x2 &= mask;
            x1 &= mask;
        }
        return x1 | x2;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {5, 5, 4, 5, 3, 3, 3};
    Solution solution;
    cout << solution.singleNumber(nums);
    
    return 0;
}
