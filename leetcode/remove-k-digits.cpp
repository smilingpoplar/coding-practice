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
        // 想象数字构成的高低折线，每次都削掉第一个"波峰"，就能使数字最小
        // 用栈找"波峰"，即找下一个更小的数
        string s;
        for (char c : num) {
            while (!s.empty() && c < s.back() && k > 0) {
                s.pop_back(); // 弹出数是波峰，削掉第一个波峰
                k--;
            }
            s.push_back(c);
        }
        // 满足特定条件才削峰，上面削掉的可能不够k个。栈中是递增序列，继续削
        while (!s.empty() && k > 0) {
            s.pop_back();
            k--;
        }
        // 删除开头的0
        int pos = 0;
        while (pos < s.size() && s[pos] == '0') pos++;
        return pos < s.size() ? s.substr(pos) : "0";
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
