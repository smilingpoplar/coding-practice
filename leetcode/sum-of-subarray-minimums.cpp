//
//  sum-of-subarray-minimums
//  https://leetcode.com/problems/sum-of-subarray-minimums/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        // 求各个连续子段最小值的和。
        // 什么时候A[i2]是子段的最小值？子段可往左扩展到下一个<A[i2]的位置i1（不含i1），
        // 往右扩展到下一个<A[i2]的位置i3（不含i3），则A[i2]作最小值的子段有(i2-i1)*(i3-i2)个
        // 找下一个<A[i2]的位置 <=> 用栈找波峰，波峰的两侧就是下一个<波峰的位置
        const int MOD = 1e9 + 7;
        int ans = 0;
        stack<int> stk; // 保存idx，递增栈
        A.push_back(0); // 右哨兵
        for (int i3 = 0; i3 < A.size(); i3++) {
            while (!stk.empty() && A[i3] < A[stk.top()]) {
                int i2 = stk.top(); stk.pop();
                int i1 = stk.empty() ? -1 : stk.top();
                ans = (ans + A[i2] * (i2 - i1) * (i3 - i2)) % MOD;
            }
            stk.push(i3);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
