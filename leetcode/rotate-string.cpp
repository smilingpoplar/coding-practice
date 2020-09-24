//
//  rotate-string
//  https://leetcode.com/problems/rotate-string/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        // 如果A左旋后可以得到B，那么AA中包含B
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
