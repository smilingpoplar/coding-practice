//
//  judge-route-circle
//  https://leetcode.com/problems/judge-route-circle/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0, left = 0;
        for (char m : moves) {
            if (m == 'U') ++up;
            else if (m == 'D') --up;
            else if (m == 'L') ++left;
            else if (m == 'R') --left;
        }
        return up == 0 && left == 0;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
