//
//  integer-to-roman
//  https://leetcode.com/problems/integer-to-roman/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
        // 贪婪法
        ostringstream oss;
        int i = 0;
        while (num) {
            int cnt = num / radix[i];
            num %= radix[i];
            while (cnt) {
                oss << symbol[i];
                cnt--;
            }
            i++;
        }
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.intToRoman(98);
    
    return 0;
}
