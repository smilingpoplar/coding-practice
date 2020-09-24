//
//  decode-string
//  https://leetcode.com/problems/decode-string/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int idx = 0;
        return decodeString(s, idx);
    }
    
    // 能decode掉最外一层[xxx]
    string decodeString(string &s, int &idx) {
        string ans;
        while (idx < s.size() && s[idx] != ']') {
            if (isalpha(s[idx])) {
                ans += s[idx];
                idx++;
            } else { // 数字开头
                int num = 0;
                while (idx < s.size() && isdigit(s[idx])) {
                    num = num * 10 + s[idx] - '0';
                    idx++;
                }
                idx++; // [
                string sub = decodeString(s, idx);
                idx++; // ]
                while (num--) ans += sub;
            }
        }
        return ans;
    }    
};

int main(int argc, const char * argv[]) {    
    return 0;
}
