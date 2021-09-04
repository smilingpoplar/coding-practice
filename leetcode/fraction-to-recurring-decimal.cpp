//
//  fraction-to-recurring-decimal
//  https://leetcode.com/problems/fraction-to-recurring-decimal/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
        bool neg = (numerator ^ denominator) < 0;
        if (neg) ans += "-";

        long n = labs(numerator), d = labs(denominator);
        ans += to_string(n / d);
        
        long rmd = n % d;
        if (rmd > 0) ans += ".";
        
        // 为插入循环节的左括号，记录 余数=>对应左括号应在ans串的位置
        unordered_map<long, int> mp; 
        while (rmd) {
            if (mp.count(rmd)) { // 找到循环节
                ans.insert(mp[rmd], "(");
                ans += ")";
                return ans;
            }

            mp[rmd] = ans.size();
            rmd *= 10;
            ans += to_string(rmd / d);
            rmd %= d;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.fractionToDecimal(2, 3);
    
    return 0;
}
