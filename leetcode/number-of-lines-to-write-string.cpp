//
//  number-of-lines-to-write-string
//  https://leetcode.com/problems/number-of-lines-to-write-string/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        const int MAX_WIDTH = 100;
        int line = 0, width = 0;
        for (char c : S) {
            int w = widths[c - 'a'];
            if (width + w > MAX_WIDTH) {
                line++;
                width = 0;
            }
            width += w;
        }
        if (width > 0) line++;
        return {line, width};
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
