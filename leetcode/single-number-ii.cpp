//
//  single-number-ii.cpp
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
        int one = 0; // 用one记录到当前处理的元素为止，二进制1出现1次（mod 3）的那些位
        int two = 0; // 用two记录到当前处理的元素为止，二进制1出现2次（mod 3）的那些位
        for (auto num : nums) {
            two |= one & num; // two：原0遇1 ->1，原1遇1（即二进制1出现了4次，这里不会遇到这种情况，因为后面出现3次时就做了清零）
            one ^= num; // one：原0遇1 ->1, 原1遇1（即出现两次要统计到two中）->0，所以异或
            int clearThree = ~(one & two); // 出现3次的二进制1进行清零
            one &= clearThree;
            two &= clearThree;
        }
        return one;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {5, 5, 4, 5, 3, 3, 3};
    Solution solution;
    cout << solution.singleNumber(nums);
    
    return 0;
}
