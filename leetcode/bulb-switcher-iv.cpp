//
//  maximal-square
//  https://leetcode.com/problems/maximal-square/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minFlips(string target) {
        // 数数有几个不同子段
        char prev = '0';
        int ans = 0;
        for (char c : target) {
            if (c != prev) {
                ans++;
                prev = c;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
