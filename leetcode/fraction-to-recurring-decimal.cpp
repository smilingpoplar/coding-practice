//
//  fraction-to-recurring-decimal
//  https://leetcode.com/problems/fraction-to-recurring-decimal/
//
//  Created by smilingpoplar on 15/8/21.
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
        bool negative = (numerator ^ denominator) < 0;
        if (negative) result += "-";

        auto n = abs((long long)numerator);
        auto d = abs((long long)denominator);
        auto integral = n / d;
        result += to_string(integral);
        
        auto remainder = n % d;
        if (remainder > 0) result += ".";
        
        unordered_map<long long, ssize_t> m;
        while (remainder > 0) {
            if (m.find(remainder) != m.end()) {
                result.insert(m[remainder], "(");
                result += ")";
                break;
            }
            m[remainder] = result.size();
            
            remainder *= 10;
            auto quotient = remainder / d;
            result += to_string(quotient);
            remainder %= d;
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.fractionToDecimal(2, 3);
    
    return 0;
}
