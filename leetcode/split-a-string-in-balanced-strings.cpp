//
//  split-a-string-in-balanced-strings
//  https://leetcode.com/problems/split-a-string-in-balanced-strings/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0, ans = 0;
        for (char c : s) {
            if (c == 'R') cnt++;
            else cnt--;
            if (cnt == 0) ans++;            
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
