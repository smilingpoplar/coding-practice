//
//  ugly-number-ii
//  https://leetcode.com/problems/ugly-number-ii/
//
//  Created by smilingpoplar on 15/5/21.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> seq;
        seq.push_back(1);
        // 每个因子对应一个要相乘的丑数，用以生成下个丑数
        int i2 = 0, i3 = 0, i5 = 0; // ix是索引
        for (int i = 1; i < n; i++) {
            int next = min({ seq[i2] * 2, seq[i3] * 3, seq[i5] * 5 });
            seq.push_back(next);
            if (next == seq[i2] * 2) ++i2;
            if (next == seq[i3] * 3) ++i3;
            if (next == seq[i5] * 5) ++i5;
        }
        
        return seq[n - 1];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.nthUglyNumber(5);
    
    return 0;
}
