//
//  excel-sheet-column-number
//  https://leetcode.com/problems/excel-sheet-column-number/
//
//  Created by smilingpoplar on 15/6/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result = result * 26 + (s[i] - 'A' + 1);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.titleToNumber("AB");
 
    return 0;
}