//
//  repeated-substring-pattern
//  https://leetcode.com/problems/repeated-substring-pattern/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) < s.size();        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
