//
//  fraction-to-recurring-decimal
//  https://leetcode.com/problems/fraction-to-recurring-decimal/
//
//  Created by smilingpoplar on 15/6/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "NAN";
        if (numerator == 0) return "0";
        
        string result;
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }
        // abs(INT_MIN)溢出为INT_MIN，用"long long"避免溢出
        auto llNumerator = abs((long long)numerator);
        auto llDenominator = abs((long long)denominator);
        auto quotient = llNumerator / llDenominator;
        result += to_string(quotient);
        auto remainder = llNumerator % llDenominator;
        if (remainder == 0) return result;
        result += ".";
        
        unordered_map<long long, size_t> m; // 记录remainder的商在结果串中的位置
        while (remainder) {
            if (m.find(remainder) != m.end()) { // remainder曾出现过
                auto pos = m[remainder];
                result.insert(pos, "(");
                result += ")";
                break;
            }
            m[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / llDenominator);
            remainder %= llDenominator;
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.fractionToDecimal(-1, INT_MIN);
    
    return 0;
}
