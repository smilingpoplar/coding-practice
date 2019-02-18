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
        // 将N的串表示从右往左不断将波峰减1，
        // 再将最左波峰后面的所有数字变为9。
        string s = to_string(N);
        int idx = s.size();
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] > s[i+1]) {
                s[i]--;
                idx = i;
            }
        }
        for (int i = idx + 1; i < s.size(); i++) {
            s[i] = '9';
        }
        return stoi(s);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
