//
//  student-attendance-record-i
//  https://leetcode.com/problems/student-attendance-record-i/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, ll = 0;
        for (char c : s) {
            if (c == 'L') {
                ll++;
            } else {
                ll = 0;
                if (c == 'A') {
                    a++;
                }
            }
            if (a > 1 || ll > 2) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
