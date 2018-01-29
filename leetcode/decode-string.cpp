//
//  decode-string
//  https://leetcode.com/problems/decode-string/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int idx = 0;
        return decodeString(s, idx);
    }
    
    // 假设这个函数能decode掉最上一层[xxx]
    string decodeString(string &s, int &idx) {
        string res;
        while (idx < s.size() && s[idx] != ']') {
            if (isalpha(s[idx])) {
                res += s[idx];
                idx++;
            } else { // 数字开头
                int n = 0;
                while (idx < s.size() && isdigit(s[idx])) {
                    n = n * 10 + s[idx] - '0';
                    idx++;
                }
                idx++; // [
                string sub = decodeString(s, idx);
                idx++; // ]
                while (n--) {
                    res += sub;
                }
            }
        }
        return res;
    }    
};

int main(int argc, const char * argv[]) {    
    return 0;
}
