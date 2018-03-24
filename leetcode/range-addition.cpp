//
//  range-addition
//  https://leetcode.com/problems/range-addition/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // 要执行许多更新操作，想到把更新操作简化。
        // 这里把更新操作记在范围边界上，相当于只记录在范围边界发生的变化量。
        // 对于[startIdx, endIdx, inc]，在startIdx记录+inc，在endIdx+1记录-inc。
        // 最后将所有变化量累加，相当于让变化生效。
        vector<int> ans(length, 0);
        for (auto &update : updates) {
            int start = update[0], end = update[1], inc = update[2];
            ans[start] += inc;
            if (end + 1 < length) ans[end + 1] -= inc;
        }
        for (int i = 1; i < length; i++) {
            ans[i] += ans[i-1];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
