//
//  string-to-integer-atoi
//  https://leetcode.com/problems/string-to-integer-atoi/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        const int N = str.size();
        int i = 0;
        while (i < N && str[i] == ' ') i++;
        // 符号
        int sign = 1;
        if (i < N && (str[i] == '+' || str[i] == '-')) {
            if (str[i] == '-') sign = -1;
            i++;
        }
        
        int ans = 0;
        while (i < N && isdigit(str[i])) {
            // ans * 10 + (str[i] - '0') > INT_MAX，溢出
            if (ans > (INT_MAX - (str[i] - '0')) / 10) 
                return sign == 1 ? INT_MAX : INT_MIN;
            ans = ans * 10 + str[i] - '0';
            i++;
        }
        return sign * ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.myAtoi(" -10a");
    
    return 0;
}
