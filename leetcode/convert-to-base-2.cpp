//
//  convert-to-base-2
//  https://leetcode.com/problems/convert-to-base-2/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string baseNeg2(int N) {
        // 不能用%-2操作，因为需要余数为正
        string ans;
        while (N) {
            int rem = N & 1;
            ans = to_string(rem) + ans;
            N = -(N >> 1);
        }
        return !ans.empty() ? ans : "0";
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
