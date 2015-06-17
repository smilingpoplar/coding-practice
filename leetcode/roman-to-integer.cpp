//
//  roman-to-integer
//  https://leetcode.com/problems/roman-to-integer/
//
//  Created by smilingpoplar on 15/6/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        // 从左到右扫描，累加当前值，如果当前字符比上一个大，补减上一个值
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            result += value[s[i]];
            if (i > 0 && value[s[i]] > value[s[i - 1]]) {
                result -= 2 * value[s[i - 1]];
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.romanToInt("XCVIII");
    
    return 0;
}