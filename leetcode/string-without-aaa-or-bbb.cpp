//
//  string-without-aaa-or-bbb
//  https://leetcode.com/problems/string-without-aaa-or-bbb/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        if (A == 0) return string(B, 'b');
        if (B == 0) return string(A, 'a');
        if (A > B) return "aab" + strWithout3a3b(A-2, B-1);
        if (A < B) return "bba" + strWithout3a3b(A-1, B-2);
        return "ab" + strWithout3a3b(A-1, B-1);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
