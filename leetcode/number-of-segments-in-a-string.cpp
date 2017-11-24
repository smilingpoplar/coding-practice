//
//  number-of-segments-in-a-string
//  https://leetcode.com/problems/number-of-segments-in-a-string/
//
//  Created by smilingpoplar on 17/11/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((i == 0 || s[i-1] == ' ') && s[i] != ' ') { // 单词开头
                count++;
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
