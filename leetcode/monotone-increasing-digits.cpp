//
//  monotone-increasing-digits
//  https://leetcode.com/problems/monotone-increasing-digits/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        // 从后往前，找下降的相邻数对，将其中前一个减1
        // 记住最终减1的位置，把它后面所有的数都变成'9'
        string s = to_string(N);
        int pos = s.size();
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] > s[i+1]) {
                s[i]--;
                pos = i;
            }
        }
        for (int i = pos + 1; i < s.size(); i++) {
            s[i] = '9';
        }
        return stoi(s);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
