//
//  path-in-zigzag-labelled-binary-tree
//  https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    inline int pow2(int n) {
        return 1 << n;
    }
    
    vector<int> pathInZigZagTree(int label) {
        // 第h层（0-based）的label范围[2^h..2^(h+1)-1]
        int h = 0;
        while (pow2(h+1) - 1 < label) {
            h++;
        }
        
        vector<int> ans;
        while (label) {
            ans.push_back(label);
            // 每层都与上一层方向相反
            label = (pow2(h) + pow2(h+1) - 1 - label) / 2;
            h--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
