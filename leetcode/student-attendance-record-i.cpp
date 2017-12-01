//
//  student-attendance-record-i
//  https://leetcode.com/problems/student-attendance-record-i/
//
//  Created by smilingpoplar on 17/12/01.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        int continuousLate = 0;
        for (char c : s) {
            if (c == 'L') {
                ++continuousLate;
            } else {
                continuousLate = 0;
                if (c == 'A') {
                    ++absent;
                }
            }
            if (absent > 1 || continuousLate > 2) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
