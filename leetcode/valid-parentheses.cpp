//
//  valid-parentheses
//  https://leetcode.com/problems/valid-parentheses/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> stk;
        for (char c : s) {
            if (mp.count(c)) {
                stk.push(mp[c]);
            } else if (stk.empty()) {
                return false;
            } else if (stk.top() != c) {
                return false;
            } else {
                stk.pop();
            }
        }
        return stk.empty();
    }
};

int main(int argc, const char* argv[]) {
    Solution solution;
    cout << solution.isValid("()[]{}");

    return 0;
}
