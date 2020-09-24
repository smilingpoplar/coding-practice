//
//  make-the-string-great
//  https://leetcode.com/problems/make-the-string-great/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string ans;
        for (char c : s) {
            if (!ans.empty() && (ans.back() ^ c) == 32) {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
