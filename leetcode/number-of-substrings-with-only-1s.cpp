//
//  number-of-substrings-with-only-1s
//  https://leetcode.com/problems/number-of-substrings-with-only-1s/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        int count = 0, ans = 0;
        for (char c : s) {
            if (c == '1') count++;
            else count = 0;
            ans = (ans + count) % MOD;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
