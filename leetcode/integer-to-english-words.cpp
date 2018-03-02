//
//  integer-to-english-words
//  https://leetcode.com/problems/integer-to-english-words/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<string> THOUSANDS = { "Billion", "Million", "Thousand", "" };
    vector<string> TENS = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> LESS20 = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    vector<int> RADIX = { 1000000000, 1000000, 1000, 1 };
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string ans;
        for (int i = 0; i < RADIX.size(); i++) {
            if (num / RADIX[i] == 0) continue;
            ans += less1000(num / RADIX[i]) + THOUSANDS[i] + " ";
            num %= RADIX[i];
        }
        return ans.erase(ans.find_last_not_of(' ') + 1);
    }
    
    string less1000(int num) { // 末尾带空格
        if (num == 0) return "";
        if (num < 20) return LESS20[num] + " ";
        if (num < 100) return TENS[num / 10] + " " + less1000(num % 10);
        if (num < 1000) return LESS20[num / 100] + " Hundred " + less1000(num % 100);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
