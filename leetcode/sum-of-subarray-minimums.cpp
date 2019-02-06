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
        // 求所有子段最小值的和。那A[i]什么时候是子段的最小值？
        // 从位置i往左扩展到下一个<A[i]的位置i1，往右扩展到下一个<A[i]的位置i2，
        // 以A[i]作最小值的子段往左有(i-i1)个、往右有(i2-i)个，总共有(i-i1)*(i2-i)个
        // 找下一个更小的数 <=> 用栈找波峰，波峰的两侧都是下一个<波峰的数
        const int MOD = 1e9 + 7;
        int ans = 0;
        stack<int> stk; // 保存idx，递增栈
        A.push_back(0); // 右哨兵
        for (int i2 = 0; i2 < A.size(); i2++) {
            while (!stk.empty() && A[i2] < A[stk.top()]) {
                int i = stk.top(); stk.pop();
                int i1 = stk.empty() ? -1 : stk.top();
                ans = (ans + A[i] * (i - i1) * (i2 - i)) % MOD;
            }
            stk.push(i2);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
