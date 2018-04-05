//
//  basic-calculator
//  https://leetcode.com/problems/basic-calculator/
//
//  Created by smilingpoplar on 15/6/22.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return parseExpr(s, i);
    }
    
    // 能解析一层括号
    int parseExpr(const string &s, int &i) {
        const int N = s.size();
        char op = '+'; // 上一个未处理操作
        int sum = 0;
        for (; i < N && op != ')'; i++) {
            if (s[i] == ' ') continue;
            int num = 0;
            if (isdigit(s[i])) {
                while (i < N && isdigit(s[i]))
                    num = num * 10 + s[i++] - '0';
            } else if (s[i] == '(') {
                num = parseExpr(s, ++i);
            } 
            // 遇到新操作+-*/或结束，处理上一个操作op
            if (op == '+') sum += num;
            else if (op == '-') sum -= num;
            op = s[i];
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.calculate("(1 +(4+5+2)- 3)+(6+8)" );
    
    return 0;
}
