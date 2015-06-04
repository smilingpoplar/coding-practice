//
//  regular-expression-matching
//  https://leetcode.com/problems/regular-expression-matching/
//
//  Created by smilingpoplar on 15/6/4.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
private:
    bool isMatch(const string &s, int si, const string &p, int pi) {
        if (pi == p.size()) return si == s.size();
        
        if (pi + 1 < p.size() && p[pi + 1] == '*') {
            return isMatchStar(p[pi], s, si, p, pi + 2);
        }
        if (si < s.size() && (s[si] == p[pi] || p[pi] == '.')) {
            return isMatch(s, si + 1, p, pi + 1);
        }
        return false;
    }
    
    bool isMatchStar(const char c, const string &s, int si, const string &p, int pi) {
        while (true) {
            if (isMatch(s, si, p, pi)) return true;
            if (si < s.size() && (s[si] == c || c == '.')) ++si;
            else return false;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isMatch("a", "abc");
    
    return 0;
}