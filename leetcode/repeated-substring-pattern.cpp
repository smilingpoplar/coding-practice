//
//  repeated-substring-pattern
//  https://leetcode.com/problems/repeated-substring-pattern/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // 如果s是由子串重复而得，那s[1:]（去掉开头重复子串）、s[:-1]（去掉末尾重复子串）拼合后，ss[1:-1]应包含s
        return (s + s).substr(1, 2 * s.size() - 2).find(s) != -1;        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
