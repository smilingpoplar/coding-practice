//
//  valid-number
//  https://leetcode.com/problems/valid-number/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        const int N = s.size();
        int i = 0, j = N - 1;
        // 去掉首尾的空格
        while (i <= j && s[i] == ' ') i++;
        while (i <= j && s[j] == ' ') j--;
        if (i > j) return false;
        // 去掉开头的+/-
        if (s[i] == '+' || s[i] == '-') i++;
        
        bool num = false, exp = false, dot = false;
        while (i <= j) {
            char c = s[i];
            if (isdigit(c)) {
                num = true;
            } else if (c == 'e') {
                if (exp || !num) return false;
                exp = true;
                num = false;
            } else if (c == '.') {
                if (dot || exp) return false;
                dot = true;
            } else if (c == '+' || c == '-') {
                if (s[i - 1] != 'e') return false;
            } else {
                return false;
            }
            i++;
        }
        
        return num;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isNumber("1+1");
    
    return 0;
}
