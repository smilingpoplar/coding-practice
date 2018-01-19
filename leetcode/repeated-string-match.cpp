//
//  repeated-string-match
//  https://leetcode.com/problems/repeated-string-match/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        // A至少重复m次，使A*m总长超过B；A至多再重复1次，以从A内各字母开始匹配查找；再多重复只是重复查找
        string s;
        int count = 0;
        while (s.size() < B.size()) {
            s += A;
            ++count;
        }
        if (s.find(B) != string::npos) return count;
        // 最多再重复1次
        s += A;
        ++count;
        if (s.find(B) != string::npos) return count;
        return -1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
