//
//  binary-gap
//  https://leetcode.com/problems/binary-gap/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binaryGap(int N) {
        int lastIdx = -1, ans = 0;
        for (int i = 0; i < 32; i++) {
            if (N & (1 << i)) {
                if (lastIdx >= 0) ans = max(ans, i - lastIdx);
                lastIdx = i;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
