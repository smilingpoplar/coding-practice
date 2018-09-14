//
//  multiply-strings
//  https://leetcode.com/problems/multiply-strings/
//
//  Created by smilingpoplar on 15/6/23.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        const int M = num1.size(), N = (int)num2.size();
        string ans(M + N, 0); // 乘积最多M+N位
        
        for (auto &c : num1) c -= '0';
        for (auto &c : num2) c -= '0';
        // 将num1和num2从低位算起的第i1位和第i2位相乘，结果加到ans从低位算起的第i1+i2位
        // 换成从高位算起的视角，num1[M-1-i1] * num2[N-1-i2] +=> ans[M+N-1-(i1+i2)]
        // 设i=M-1-i1，j=N-1-i2，num1[i] * num2[j] +=> ans[i+j+1]
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                int tmp = num1[i] * num2[j] + ans[i+j+1];
                ans[i+j+1] = tmp % 10;
                ans[i+j] += tmp / 10;
            }
        }
        for (auto &c : ans) c += '0';

        int i = 0;
        while (ans[i] == '0') i++;
        if (i == ans.size()) return "0";
        return ans.substr(i);
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.multiply("789", "987");
    
    return 0;
}
