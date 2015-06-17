//
//  string-to-integer-atoi
//  https://leetcode.com/problems/string-to-integer-atoi/
//
//  Created by smilingpoplar on 15/6/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        const int N = (int)str.size();
        int i = 0;
        // 空格
        while (i < N && str[i] == ' ') ++i;
        // 符号
        int sign = 1;
        if (i < N && (str[i] == '+' || str[i] == '-')) {
            if (str[i] == '-') sign = -1;
            ++i;
        }
        
        int result = 0;
        while (i < N && '0' <= str[i] && str[i] <= '9') {
            // 溢出，[-INT_MAX,INT_MAX]都是合法范围
            if (result > (INT_MAX - (str[i] - '0')) / 10) return sign == 1 ? INT_MAX : INT_MIN;
            result = result * 10 + str[i] - '0';
            ++i;
        }
        return sign * result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.myAtoi(" -10a");
    
    return 0;
}