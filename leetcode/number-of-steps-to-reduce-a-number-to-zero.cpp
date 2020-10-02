//
//  number-of-steps-to-reduce-a-number-to-zero
//  https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        int ans = 0;
        while (num) {
            if (num & 1) num--;
            else num >>= 1;
            ans++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
