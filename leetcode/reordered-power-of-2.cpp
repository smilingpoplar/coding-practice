//
//  reordered-power-of-2
//  https://leetcode.com/problems/reordered-power-of-2/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        // 因为 N <= 10^9 = 2^30，2的幂只有31个，
        // 可以枚举这些幂，看有没有各位数字和N相同的
        auto c = counter(N);
        for (int i = 0; i < 31; i++) {
            if (c == counter(1 << i)) return true;
        }
        return false;
    }
    
    vector<int> counter(int num) {
        // 用ans[0..9]统计num的各位数字有多少个
        vector<int> ans(10, 0);
        while (num) {
            ans[num % 10]++;
            num /= 10;
        }
        return ans;
    }};

int main(int argc, const char * argv[]) {
    return 0;
}
