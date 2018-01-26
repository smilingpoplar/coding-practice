//
//  reverse-string-ii
//  https://leetcode.com/problems/reverse-string-ii/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        const int N = s.size();
        for (int i = 0; i < N; i += 2*k) {
            reverse(s, i, min(i+k-1, N-1));
        }
        return s;
    }
    
    void reverse(string &s, int b, int e) {
        while (b < e) {
            swap(s[b++], s[e--]);
        }        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}