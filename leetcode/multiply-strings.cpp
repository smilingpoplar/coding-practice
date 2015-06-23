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
        const int M = (int)num1.size();
        const int N = (int)num2.size();
        string result(M + N, 0); // 乘积最多M+N位
        
        for (auto &c : num1) c -= '0';
        for (auto &c : num2) c -= '0';
        for (int i = M - 1; i >= 0; --i) {
            int carry = 0;
            for (int j = N - 1; j >= 0; --j) {
                // 第i位和第j位相乘，结果加到第i+j+1位
                int temp = result[i + j + 1] + num1[i] * num2[j] + carry;
                result[i + j + 1] = temp % 10;
                carry = temp / 10;
            }
            result[i] += carry;
        }
        
        for (auto &c : result) c += '0';
        auto pos = result.find_first_not_of('0');
        if (pos == string::npos) return "0";
        return result.substr(pos);
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.multiply("789", "987");
    
    return 0;
}
