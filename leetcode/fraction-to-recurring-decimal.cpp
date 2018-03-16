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

        string ans;
        bool negative = (numerator ^ denominator) < 0;
        if (negative) ans += "-";

        auto n = abs((long long)numerator);
        auto d = abs((long long)denominator);
        auto integral = n / d;
        ans += to_string(integral);
        
        auto remainder = n % d;
        if (remainder > 0) ans += ".";
        
        unordered_map<long long, int> mp; // remainder=>pos
        while (remainder > 0) {
            if (mp.count(remainder)) {
                ans.insert(mp[remainder], "(");
                ans += ")";
                break;
            }
            mp[remainder] = ans.size();
            
            remainder *= 10;
            auto quotient = remainder / d;
            ans += to_string(quotient);
            remainder %= d;
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.fractionToDecimal(2, 3);
    
    return 0;
}
