//
//  length-of-last-word
//  https://leetcode.com/problems/length-of-last-word/
//
//  Created by smilingpoplar on 15/6/3.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = (int)s.size() - 1;
        while (end >= 0 && s[end] == ' ') {
            --end;
        }
        if (end < 0) return 0;
        int start = end;
        while (start >= 0 && s[start] != ' ') {
            --start;
        }
        return end - start;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.lengthOfLastWord("Hello World");
    
    return 0;
}