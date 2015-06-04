//
//  wildcard-matching
//  https://leetcode.com/problems/wildcard-matching/
//
//  Created by smilingpoplar on 15/6/4.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

// 递归解法超时
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
private:
    bool isMatch(const string &s, int si, const string &p, int pi) {
        if (pi == p.size()) return si == s.size();
        
        if (p[pi] == '*') {
            int starCount = 1;
            while (p[pi + starCount] == '*') ++starCount;
            return isMatchStar(s, si, p, pi + starCount);
        }
        if (si < s.size() && (s[si] == p[pi] || p[pi] == '?')) {
            return isMatch(s, si + 1, p, pi + 1);
        }
        return false;
    }
    
    bool isMatchStar(const string &s, int si, const string &p, int pi) {
        while (true) {
            if (isMatch(s, si, p, pi)) return true;
            if (si < s.size()) ++si;
            else return false;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isMatch("ab", "*a");
    
    return 0;
}