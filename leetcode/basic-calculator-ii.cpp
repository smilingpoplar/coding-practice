//
//  basic-calculator-ii
//  https://leetcode.com/problems/basic-calculator-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string &s) {
        // 中缀转后缀，用nums栈和ops栈
        // num先入栈，遇到下一个优先级<=栈顶的op时、先弹出计算再把op入栈。
        unordered_map<char, int> priority = {
            {'*', 2},
            {'/', 2},
            {'+', 1},
            {'-', 1},
        };

        stack<int> nums;
        stack<char> ops;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == ' ') continue;
            if (isdigit(c)) {
                int num = c - '0';
                while (i + 1 < s.size() && isdigit(s[i + 1]))
                    num = num * 10 + s[++i] - '0';
                nums.push(num);
            } else {  // +-*/
                while (!ops.empty() && priority[c] <= priority[ops.top()]) calc(nums, ops);
                ops.push(c);
            }
        }
        while (!ops.empty()) calc(nums, ops);

        return nums.top();
    }

    void calc(stack<int> &nums, stack<char> &ops) {
        if (ops.empty() || nums.size() < 2) return;
        char op = ops.top();
        ops.pop();
        int val2 = nums.top();
        nums.pop();
        int val1 = nums.top();
        nums.pop();

        if (op == '*') {
            nums.push(val1 * val2);
        } else if (op == '/') {
            nums.push(val1 / val2);
        } else if (op == '+') {
            nums.push(val1 + val2);
        } else if (op == '-') {
            nums.push(val1 - val2);
        }
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    cout << solution.calculate(" 3+5 / 2 ");

    return 0;
}
