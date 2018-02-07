//
//  remove-k-digits
//  https://leetcode.com/problems/remove-k-digits/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        // 想象数字构成的高低折线，每次都削掉第一个"高峰"，就能使数字最小
        // 找"高峰"的问题，用栈，即找下一个更小的数
        int keep = num.size() - k;
        string s;
        for (char c : num) {
            while (!s.empty() && c < s.back() && k > 0) {
                s.pop_back(); // 削掉第一个"高峰"
                k--;
            }
            s.push_back(c);
        }
        // 万一削掉的"高峰"不够k个
        s.resize(keep);
        // 删除开头的0
        while (!s.empty() && s[0] == '0') {
            s.erase(s.begin());
        }
        return !s.empty() ? s : "0";
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
