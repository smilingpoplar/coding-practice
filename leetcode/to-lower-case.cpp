//
//  to-lower-case
//  https://leetcode.com/problems/to-lower-case/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for (char &c : str) {
            if ('A' <= c && c <= 'Z') c += 32;
        }
        return str;
    }};

int main(int argc, const char * argv[]) {
    return 0;
}
