//
//  integer-to-roman
//  https://leetcode.com/problems/integer-to-roman/
//
//  Created by smilingpoplar on 15/6/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const vector<int> radix = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        ostringstream oss;
        int i = 0;
        while (num) {
            int count = num / radix[i];
            num %= radix[i];
            while (count) {
                oss << symbol[i];
                --count;
            }
            ++i;
        }
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.intToRoman(98);
    
    return 0;
}