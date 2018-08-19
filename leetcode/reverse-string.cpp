//
//  reverse-string
//  https://leetcode.com/problems/reverse-string/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
