//
//  ternary-expression-parser
//  https://leetcode.com/problems/ternary-expression-parser/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string parseTernary(string expression) {
        // 三元运算是右结合，所以先处理最右的'?'，从右往左扫
        stack<char> stk;
        for (int i = (int)expression.size() - 1; i >= 0; i--) {
            char c = expression[i];
            if (c == '?') {
                auto expr1 = stk.top(); stk.pop();
                stk.pop(); // 略过:
                auto expr2 = stk.top(); stk.pop();
                stk.push(expression[i-1] == 'T' ? expr1 : expr2);
                i--; // 略过?前的T或F
            } else {
                stk.push(c);
            }
        }
        return string(1, stk.top());
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
