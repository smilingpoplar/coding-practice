//
//  basic-calculator-ii
//  https://leetcode.com/problems/basic-calculator-ii/
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
        // 中缀转后缀，然后计算
        // 中缀转后缀，使用操作数栈和操作符栈，可参考：数据结构与算法分析=>3.3.3=>3
        // 1. 操作数的入栈顺序不变；操作符入栈前，要先处理操作符栈中优先级较高或同等的操作符
        unordered_map<char, int> priority = {
            {'*', 2},
            {'/', 2},
            {'+', 1},
            {'-', 1},
        };
        
        vector<int> operands;
        vector<char> operators;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == ' ') continue;
            if ('0' <= c && c <= '9') {
                int num = c - '0';
                while (i + 1 < s.size() && '0' <= s[i + 1] && s[i + 1] <= '9') {
                    num = num * 10 + s[i + 1] - '0';
                    ++i;
                }
                operands.push_back(num);
            } else if (operators.empty() || priority[c] > priority[operators.back()]) {
                operators.push_back(c);
            } else { // '*'||'/'||'+'||'-'
                while (!operators.empty() && priority[c] <= priority[operators.back()]) {
                    calculate(operands, operators);
                }
                operators.push_back(c);
            }
        }
        while (!operators.empty()) {
            calculate(operands, operators);
        }
        
        return operands.back();
    }

private:
    void calculate(vector<int> &operands, vector<char> &operators) {
        if (operators.empty() || operands.size() < 2) return;
        char op = operators.back();
        operators.pop_back();
        int value2 = operands.back();
        operands.pop_back();
        int value1 = operands.back();
        operands.pop_back();
        if (op == '*') {
            operands.push_back(value1 * value2);
        } else if (op == '/') {
            operands.push_back(value1 / value2);
        } else if (op == '+') {
            operands.push_back(value1 + value2);
        } else if (op == '-') {
            operands.push_back(value1 - value2);
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.calculate(" 3+5 / 2 ");
    
    return 0;
}
