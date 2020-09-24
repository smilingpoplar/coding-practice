//
//  range-addition
//  https://leetcode.com/problems/range-addition/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // 将区间[l,r]的值增加inc，只在区间边界记录变化量：arr[l]+=inc; arr[r+1]-=inc;
        // 然后idx处的值就是前缀和sum[0..idx]
        vector<int> ans(length, 0);
        for (auto &update : updates) {
            int l = update[0], r = update[1], inc = update[2];
            ans[l] += inc;
            if (r + 1 < length) ans[r+1] -= inc;
        }
        // 将ans数组从增量变成前缀和
        for (int i = 1; i < length; i++) {
            ans[i] += ans[i-1];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
