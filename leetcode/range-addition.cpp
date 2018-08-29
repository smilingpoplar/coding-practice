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
        // 只在区间边界记录变化量：
        // 对于[startIdx, endIdx, inc]，在startIdx记录+inc，在endIdx+1记录-inc
        vector<int> ans(length, 0);
        for (auto &update : updates) {
            int start = update[0], end = update[1], inc = update[2];
            ans[start] += inc;
            if (end + 1 < length) ans[end+1] -= inc;
        }
        // 最后将变化量累加
        for (int i = 1; i < length; i++) {
            ans[i] += ans[i-1];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
