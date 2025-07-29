//
//  zigzag-conversion
//  https://leetcode.com/problems/zigzag-conversion/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int rowIdx = 0, dir = 1;
        vector<string> rows(numRows);
        for (char c : s) {
            rows[rowIdx].push_back(c);

            if (rowIdx == numRows - 1) {
                dir = -1;
            } else if (rowIdx == 0) {
                dir = 1;
            }
            rowIdx += dir;
        }

        string ans;
        for (auto &row : rows) {
            ans += row;
        }
        return ans;
    }
};