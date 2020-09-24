//
//  maximum-69-number
//  https://leetcode.com/problems/maximum-69-number/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        auto s = to_string(num);
        for (char &c : s) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        return stoi(s);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
