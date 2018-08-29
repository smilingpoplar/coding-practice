//
//  range-addition-ii
//  https://leetcode.com/problems/range-addition-ii/
//
//  Created by smilingpoplar on 17/12/02.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mina = m, minb = n;
        for (auto &op : ops) {
            mina = min(mina, op[0]);
            minb = min(minb, op[1]);
        }
        return mina * minb;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
