//
//  basic-calculator-iii
//  https://leetcode.com/problems/basic-calculator-iii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return parseExpr(s, i);
    }
    
    // 解析一层括号
    int parseExpr(const string &s, int &i) {
        const int N = s.size();
        char op = '+'; // 上一个未处理op
        vector<int> nums;
        for (; i < N && op != ')'; i++) { // 尚有未处理op
            if (s[i] == ' ') continue;
            int num = 0;
            if (isdigit(s[i])) {
                while (i < N && isdigit(s[i]))
                    num = num * 10 + s[i++] - '0';
            } else if (s[i] == '(') {
                num = parseExpr(s, ++i);
            } 
            // 遇到新操作+-*/或结束，处理上一个op
            if (op == '+') nums.push_back(num);
            else if (op == '-') nums.push_back(-num);
            else if (op == '*') nums.back() *= num;
            else if (op == '/') nums.back() /= num;
            op = s[i];
        }
        
        int ans = 0;
        for (int num : nums) 
            ans += num;
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
